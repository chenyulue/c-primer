#include <stdio.h>
#include <string.h>
#include <ctype.h>

int display_menu(void);
int get_lines(char (*line)[40], int max_lines);
void str_sort(char *line[], int max_lines);
void str_sort_by_length(char *line[], int max_lines);
void str_sort_by_length_of_first_word(char *line[], int max_lines);
unsigned wdlen(char * line);

int main(void)
{
    int choice, line_num;
    char lines[10][40];
    char * ptstr[10];

    choice = display_menu();
    while (choice != 5)
    {
        printf("Enter at most 10 lines of strings (EOF to quit):\n");
        line_num = get_lines(lines, 10);
        for (int i = 0; i < line_num; i++)
            ptstr[i] = lines[i];
        switch (choice)
        {
            case 1: for (int i = 0; i < line_num; i++)
                        fputs(lines[i], stdout);
                    break;
            case 2: str_sort(ptstr, line_num);
                    break;
            case 3: str_sort_by_length(ptstr, line_num);
                    break;
            case 4: str_sort_by_length_of_first_word(ptstr, line_num);
        }
        choice = display_menu();
    }

    return 0;
}

int display_menu(void)
{
    int choice, status;

    printf("Print the list of strings in order of ____?\n");
    printf("1) original sequence    2) ASCII collating sequence\n"
            "3) string length        4) length of the first word\n"
            "5) quit\n");
    printf("?> ");
    status = scanf("%d", &choice);
    while (status != 1 || choice > 5 || choice < 1)
    {
        while (getchar() != '\n')  // consume the rest inputs
            continue;
        printf("\nPrint the list of strings in order of ____?\n");
        printf("1) original sequence    2) ASCII collating sequence\n"
                "3) string length        4) length of the first word\n"
                "5) quit\n");
        printf("Tip: only 1 to 5 are allowed.\n");
        printf("?> ");
        status = scanf("%d", &choice);   
    }
    while (getchar() != '\n')    // consume the rest inputs
        continue;

    return choice;
}

int get_lines(char (*line)[40], int max_lines)
{
    int i, count;

    for (i = 0, count = 0; i < max_lines; i++, count++)
    {
        if (!fgets(line[i], 40, stdin))
            break;
    }
    //while (getchar() != -1 || getchar() != '\n')
    //    continue;

    return count;
}

void str_sort(char *line[], int max_lines)
{
    int i, j;
    char *tmp;

    for (i = 0; i < max_lines; i++)
    {
        for (j = i + 1; j < max_lines; j++)
        {
            if (strcmp(line[i], line[j]) > 0)
            {
                tmp = line[i];
                line[i] = line[j];
                line[j] = tmp;
            }
        }
    }
    for (i = 0; i < max_lines; i++)
        fputs(line[i], stdout);
}
void str_sort_by_length(char *line[], int max_lines)
{
    int i, j;
    char *tmp;

    for (i = 0; i < max_lines; i++)
    {
        for (j = i + 1; j < max_lines; j++)
        {
            if (strlen(line[i]) > strlen(line[j]))
            {
                tmp = line[i];
                line[i] = line[j];
                line[j] = tmp;
            }
        }
    }
    for (i = 0; i < max_lines; i++)
        fputs(line[i], stdout);
}
void str_sort_by_length_of_first_word(char *line[], int max_lines)
{
    int i, j;
    char *tmp;

    for (i = 0; i < max_lines; i++)
    {
        for (j = i + 1; j < max_lines; j++)
        {
            if (wdlen(line[i]) > wdlen(line[j]))
            {
                tmp = line[i];
                line[i] = line[j];
                line[j] = tmp;
            }
        }
    }
    for (i = 0; i < max_lines; i++)
        fputs(line[i], stdout);    
}

unsigned wdlen(char * line)
{
    unsigned count;

    while (isspace(*line))
        line++;
    count = 0;
    while (!isspace(*line))
    {
        line++;
        count++;
    }
 
    return count;
}