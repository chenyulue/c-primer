#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CH17_EX3_H_
#include "ch17_ex2.h"

void showmovies(Item item);
char * s_gets(char * st, int n);

int main(void)
{
    List movies;
    Item temp;

    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fputs("No memory available! Bye!", stderr);
        exit(1);
    }
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n')
            continue;
        if (AddItem(temp, &movies) == false)
        {
            fputs("Problem allocating memory.", stderr);
            break;
        }
        if (ListIsFull(&movies))
        {
            fputs("The list is now full.", stderr);
            break;
        }
        puts("Enter next movie title (empty line to stop): ");
    }

    if (ListIsEmpty(&movies))
        puts("No data entered.");
    else
    {
        puts("Here is the movie list:");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));

    EmptyTheList(&movies);
    puts("Bye!");

    return 0;
}

void showmovies(Item item)
{
    printf("Movie: %s\tRating: %d\n", item.title, item.rating);
}

char * s_gets(char * st, int n)
{
    char * ret_val, * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n');
    }
    return ret_val;
}