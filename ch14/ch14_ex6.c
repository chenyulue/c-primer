#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ch14_ex6.h"

#define BUFSIZE 256

static void calc_info(Player * players, int num);
static char * get_name(const Player * player);

int main(void)
{
    FILE * fp;
    char file[BUFSIZE];
    int total;
    Player plyers[SIZE] = {{0, {"",""}, 0, 0, 0, 0, 0}};

    printf("Enter the data file\n> ");
    s_gets(file, BUFSIZE);
    if ((fp = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "Error in opening the file: %s\n", file);
        exit(EXIT_FAILURE);
    }
    total = read_info(fp, plyers, SIZE);
    calc_info(plyers, SIZE);
    printf("\n_________________________________\n"
           "|    The baseball statistics    |\n"
           "---------------------------------\n");
    show_info(plyers, SIZE, total);
    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing the file: %s\n", file);

    return 0;
}

char * s_gets(char * str, int num)
{
    char * ret_val;
    char * find;

    ret_val = fgets(str, num, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

int read_info(FILE * fp, Player * players, int number)
{
    int bats, hits, walks, RBIs, num;
    int status, line, total;
    char first[40], last[40];
    char record[BUFSIZE];

    line = 1;
    total = 0;
    while (1)
    {
        /* First read in the player information. If failing to read, report errors and skip the line. */
        if (fgets(record, BUFSIZE, fp) == NULL)
        {
            break;
        }
        status = sscanf(record, "%d %s %s %d %d %d %d", &num, first, last, &bats, &hits, &walks, &RBIs);
        if (status != 7)
        {
            fprintf(stderr, "Error in reading: malformed data in line %d:\n", line);
            puts(record);
            line++;
            continue;
        }
        if (num >= number)
        {
            fprintf(stderr, "Error in the player number: read %d >= maximum %d.\n", num, number-1);
            continue;
        }
        /* The player's information has not been read in. Then assign the player number and name to 
           the corresponding member of the structure. */
        if (players[num].first_name[0] == '\0')  
        {
            players[num].player_num = num;
            strcpy(players[num].first_name, first); 
            strcpy(players[num].last_name, last);
            total++;
        }
        players[num].bats += bats;
        players[num].hits += hits;
        players[num].walks += walks;
        players[num].RBIs += RBIs;
        line++;
    }
    printf("Reading Done!\n");

    return total;
}
void show_info(const Player * players, int num, int total)
{
    int i;
    int bats = 0, hits = 0, walks = 0, RBIs = 0;
    float batavg = 0.0f;

    printf("%-7s %-20s %-7s %-7s %-7s %-7s %-10s\n", "No.", "Name", "Bats", "Hits", "Walks", "RBIs", "Batting Average");
    for (i = 0; i < num; i++)
    {
        if (players[i].first_name[0] == '\0')
            continue;
        char * name = get_name(&players[i]);
        printf("%-7d %-20s %-7d %-7d %-7d %-7d %-10.2f\n", players[i].player_num, name, players[i].bats, 
                players[i].hits, players[i].walks, players[i].RBIs, players[i].batavg);
        bats += players[i].bats;
        hits += players[i].hits;
        walks += players[i].walks;
        RBIs += players[i].RBIs;
        batavg += players[i].batavg;
        free(name);
    }
    printf("%-28s %-7.2f %-7.2f %-7.2f %-7.2f %-10.2f\n", "Statistics for the team", 
            (float) bats/total, (float) hits/total, (float) walks/total, (float) RBIs/total, batavg/total);
}

void calc_info(Player * players, int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        if (players[i].bats != 0)
            players[i].batavg = (float) players[i].hits / players[i].bats;
    }
}

char * get_name(const Player * player)
{
    const char * first = player->first_name;
    const char * last = player->last_name;
    char * name = malloc(sizeof (first) + sizeof (last) + 1);

    strcpy(name, first);
    strcat(name, " ");
    strcat(name, last);

    return name;
}