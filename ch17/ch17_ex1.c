#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

typedef struct film {
    char title[TSIZE];
    int rating;
    struct film * next;
    struct film * prev;
} Film;
char * s_gets(char * st, int n);

int main(void)
{
    Film * head = NULL;
    Film * prev, * current;
    char input[TSIZE];

    puts("Enter first movie title: ");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (Film *)malloc(sizeof(Film));
        if (head == NULL)
        {   
            head = current;
            head->prev = NULL;
        }
        else
        {    
            prev->next = current;
            current->prev = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>: ");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop): ");
        prev = current;
    }
    if (head == NULL)
        puts("No data entered.");
    else
        puts("Here is the movie list: ");
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        prev = current;
        current = current->next;
    }
    if (head != NULL)
        puts("\nHere is the move list in reverse order:");
    while (prev != NULL)
    {
        printf("Movie: %s Rating: %d\n", prev->title, prev->rating);
        prev = prev->prev;
    }

    current = head;
    while (current != NULL)
    {
        Film * tmp = current->next;
        free(current);
        current = tmp;
    }
    printf("Bye!\n");

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