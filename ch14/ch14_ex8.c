#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CAPACITY 12

typedef struct name_st {
    char first[40];
    char last[40];
} Name;

typedef struct seat_st {
    Name name;
    char id[3];
    bool assigned;
} Seat;

void menu(void);
int show_empty(const Seat seats[], int num, bool list);
void show_seats(const Seat seats[], int num);
void assign_seat(Seat seats[], int num);
void delete_assignment(Seat seats[], int num);
char * get_name (const Seat * s);
char * s_gets(char * st, int n);

int main(void)
{
    Seat seatarr[CAPACITY];
    FILE * pseat;
    int count = 0;
    char code[2];
    char * s;

    if ((pseat = fopen("seats.dat", "r+b")) == NULL)
    {
        if ((pseat = fopen("seats.dat", "w+b")) == NULL)
        {
            fputs("Can't open the seats.dat file", stderr);
            exit(EXIT_FAILURE);
        }
        printf("Enter the seat ID:\n");
        while (count < CAPACITY)
        {
            scanf("%s", seatarr[count].id);
            seatarr[count].name.first[0] = '\0';
            seatarr[count].name.last[0] = '\0';
            seatarr[count].assigned = false;
            count++;
        }
        //fwrite(seatarr, sizeof (Seat), CAPACITY, pseat);
    } else
    {
        while (count < CAPACITY && fread(&seatarr[count], sizeof (Seat), 1, pseat) == 1)
        {
            count++;
        }
    }
    menu();
    while ((s = s_gets(code, 2)) != NULL && tolower(code[0]) != 'f')
    {
        switch (tolower(code[0]))
        {
            case 'a':
                printf("The number of empty seats is %d.\n", show_empty(seatarr, CAPACITY, 0));
                printf("\n");
                menu();
                break;
            case 'b':
                printf("The list of empty seats are:\n");
                show_empty(seatarr, CAPACITY, 1);
                printf("\n");
                menu();
                break;
            case 'c':
                printf("%-10s %-20s %-5s\n", "ID", "Holder Name", "Assigned");
                printf("=====================================\n");
                show_seats(seatarr, CAPACITY);
                printf("\n");
                menu();
                break;
            case 'd':
                assign_seat(seatarr, CAPACITY);
                printf("\n");
                menu();
                break;
            case 'e':
                delete_assignment(seatarr, CAPACITY);
                printf("\n");
                menu();
                break;
            case '\n':
                continue;
        }
    }
    fseek(pseat, 0, SEEK_SET);
    fwrite(seatarr, sizeof (Seat), CAPACITY, pseat);
    if (fclose(pseat) != 0)
        fputs("Error in closing the file seats.dat.\n", stderr);
    printf("Bye!\n");

    return 0;
}

void menu(void)
{
    printf("To choose a function, enter its letter label:\n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n");
    printf("Enter your choice > ");
}

int show_empty(const Seat seats[], int num, bool list)
{
    int empty_total = 0;
    int i;

    for (i = 0; i < num; i++)
    {
        if (!(seats[i].assigned))
        {
            empty_total++;
            if (list)
            {
                printf("%s\n", seats[i].id);
            }
        }
    }

    return empty_total;
}
void show_seats(const Seat seats[], int num)
{
    int i, j;
    const Seat *seatp[CAPACITY];
    char * name;

    for (i = 0; i < num; i++)
        seatp[i] = &seats[i];
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (strcmp(seatp[i]->id, seatp[j]->id) > 0)
            {
                const Seat * tmp = seatp[j];
                seatp[j] = seatp[i];
                seatp[i] = tmp;
            }
        }
    }
    for (i = 0; i < num; i++)
    {   name = get_name(seatp[i]);
        printf("%-10s %-20s %-5s\n", seatp[i]->id, name, seatp[i]->assigned ? "true" : "false");
        free(name);
    }
}
void assign_seat(Seat seats[], int num)
{
    int empty, i;
    char order[3], yes[2];
    char * s;
    
    printf("The list of empty seats:\n");
    empty = show_empty(seats, num, true);
    if (!empty)
    {
        printf("No empty seats available.\nBye!");
        return;
    }
    tryagain: printf("Enter the seat ID to order (Ctrl+Z to abort):  ");
    while ((s = s_gets(order, 3)) != NULL && order[0] == '\0')
        continue;
    if (s == NULL)
        return;
    for (i = 0; i < num; i++)
    {
        if (strcmp(order, seats[i].id) == 0 && seats[i].assigned == false)
        {
            printf("The seat %s is available. \nYes (y) to order / No (n) to abort. ", order);
            while ((s = s_gets(yes, 2)) != NULL && tolower(yes[0]) != 'y' && tolower(yes[0]) != 'n')
                continue;
            if (s == NULL)
                return;
            if (tolower(yes[0]) == 'y')
            {
                seats[i].assigned = true;
                printf("Enter your first name and last name: ");
                scanf("%s %s", seats[i].name.first, seats[i].name.last);
                while (getchar() != '\n')
                    continue;
                printf("Reservation Done!\n");
                return;
            } else
                return;
        } else if (strcmp(order, seats[i].id) == 0)
        {
            printf("The seat %s is not avaible.\nBye!\n", order);
            return;
        }
    }
    printf("The seat id doesn't exist. Try again (y/n): ");
    while ((s = s_gets(yes, 2)) != NULL && tolower(yes[0]) != 'y' && tolower(yes[0]) != 'n')
        continue;
    if (s == NULL)
        return;
    if (tolower(yes[0]) == 'y')
        goto tryagain;
    else
        return;

}
void delete_assignment(Seat seats[], int num)
{
    char id[3], yes[2];
    char * s;
    int i;

    tryagain: printf("Enter the seat ID you want to delete (Ctrl + Z to abort): ");
    while ((s = s_gets(id, 3)) != NULL && id[0] == '\0')
        continue;
    if (s == NULL)
        return;
    for (i = 0; i < num; i++)
    {
        if (strcmp(id, seats[i].id) == 0 && seats[i].assigned)
        {
            char first[40], last[40];
            
            printf("Please enter your full name to validation: ");
            scanf("%s %s", first, last);
            while (getchar() != '\n')
                continue;
            if (strcmp(first, seats[i].name.first) == 0 && strcmp(last, seats[i].name.last) == 0)
            {
                seats[i].assigned = false;
                seats[i].name.first[0] = '\0';
                seats[i].name.last[0] = '\0';
                printf("Delete Done!\n");
                return;
            } else
            {
                printf("The name entered does not conform to the information reserved.\nBye.\n");
                return;
            }
        } else if (strcmp(id, seats[i].id) == 0)
        {
            printf("The seat is not reserved. Please check your input.\nBye!\n");
            return;
        }
    }
    printf("The seat ID doesn't exist. Try again (y/n): ");
    while ((s = s_gets(yes, 2)) != NULL && tolower(yes[0]) != 'y' && tolower(yes[0]) != 'n')
        continue;
    if (s == NULL)
        return;
    if (tolower(yes[0]) == 'y')
        goto tryagain;
    else
        return;    

}

char * get_name(const Seat * s)
{
    const char * first = s->name.first;
    const char * last = s->name.last;
    char * name = malloc(sizeof(first) + sizeof(last) + 2);

    strcpy(name, first);
    strcat(name, " ");
    strcat(name, last);

    return name;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}