#include <stdio.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
typedef struct book Book;

char * s_gets(char * st, int n);
void show_info(Book * bks, int num, int code);

int main(void)
{
    Book library[MAXBKS];
    int count = 0;
    int choice;
    
    printf("Please enter the book title.\n");
    printf("Press <enter> at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
            && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        printf("How to show the list of your books:\n");
        printf("1) by the order added            2) alphabetized by title\n");
        printf("3) in order of increased value   4) quit\n");
        while (1)
        {
            if (scanf("%d", &choice) != 1)
            {
                printf("Please input an integer from 1 to 4: ");
                while (getchar() != '\n')
                    continue;
                continue;
            }
            if (choice == 4)
                break;
            printf("Here is the list of your books:\n");
            switch (choice)
            {
                case 1: show_info(library, count, 1); break;
                case 2: show_info(library, count, 2); break;
                case 3: show_info(library, count, 3); break;
                default: printf("Please input an integer from 1 to 4: "); continue;
            }
            printf("\nHow to show the list of your books:\n");
            printf("1) by the order added            2) alphabetized by title\n");
            printf("3) in order of increased value   4) quit\n");
        }
    }

    return 0;
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

void show_info(Book * bks, int num, int code)
{
    int index;
    Book * bks_list[num];

    for (index = 0; index < num; index++)
        bks_list[index] = &bks[index];
    if (code == 1)
    {
        for (index = 0; index < num; index++)
            printf("%d. %s by %s: $%.2f\n", index+1, bks_list[index]->title,
                    bks_list[index]->author, bks_list[index]->value);
    } else if (code == 2)
    {
        for (index = 0; index < num; index++)
        {   
            for (int j = index + 1; j < num; j++)
                if (strcmp(bks_list[index]->title, bks_list[j]->title) > 0)
                {
                    Book * tmp = bks_list[index];
                    bks_list[index] = bks_list[j];
                    bks_list[j] = tmp;
                }
        }
        for (index = 0; index < num; index++)
            printf("%d. %s by %s: $%.2f\n", index+1, bks_list[index]->title,
                    bks_list[index]->author, bks_list[index]->value);
    } else if (code == 3)
    {
        for (index = 0; index < num; index++)
        {
            for (int j = index + 1; j < num; j++)
                if (bks_list[index]->value > bks_list[j]->value)
                {
                    Book * tmp = bks_list[index];
                    bks_list[index] = bks_list[j];
                    bks_list[j] = tmp;
                }   
        }
        for (index = 0; index < num; index++)
            printf("%d. %s by %s: $%.2f\n", index+1, bks_list[index]->title,
                    bks_list[index]->author, bks_list[index]->value);
    }
}