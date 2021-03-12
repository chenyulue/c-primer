#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input(char *prompt);

int main(void)
{
    int word_count, i;
    char * * wdpt;
    char tmp[40];

    while ((word_count = input("How many words do you wish to enter? (enter q to quit) ")) != -1)
    {
        printf("Enter %d words now:\n", word_count);
        wdpt = malloc(word_count * sizeof (char *));
        for (i = 0; i < word_count; i++)
        {
            scanf("%s", tmp);
            wdpt[i] = malloc(strlen(tmp) + 1);
            strcpy(wdpt[i], tmp);
        }
        for (i = 0; i < word_count; i++)
        {    
            printf("%s\n", wdpt[i]);
        }
        for (i = 0; i < word_count; i++)
            free(wdpt[i]);
        free(wdpt);
        while (getchar() != '\n')
            continue;
    }
}

int input(char prompt[])
{
    int num, status;
    char ch, chr;

    printf(prompt);
    while ((status = scanf("%d", &num)) != 1 || num <= 0)
    {
        if (status == 1)
        {
            while (getchar() != '\n')
                continue;
            printf("An negative integer or zero is not allowed.\nInput a positive integer: ");
            continue;
        } else if ((chr = getchar()) != 'q')
        {
            putchar(chr);
            while ((ch = getchar ()) != '\n')
                putchar(ch);
            printf(" is not a number.\nInput a positive integer: ");
            continue;
        } else
        {
            while (getchar () != '\n')
                continue;
            return -1;
        }
    }
    while (getchar() != '\n')
        continue;
    
    return num;
}