#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int input(char prompt[]);
int main(void)
{
    int dice, roll;
    int sides;
    int status, i;
    int * roll_cases;

    srand((unsigned int) time(0));

    roll = input("Enter the number of sets; enter q to stop: ");
    while (roll != -1)
    {
        printf("How many sides and how many dice? (enter q to stop) ");
        sides = input("");
        dice = input("");
        roll_cases = malloc(roll * sizeof (int));
        for (i = 0; i < roll; i++)
        {
            int tmp;
            tmp = roll_n_dice(dice, sides);
            if (tmp == -1)
            {
                free(roll_cases);
                exit(EXIT_FAILURE);
            }
            roll_cases[i] = tmp;
        }
        printf("Here are %d sets of %d %d-sided throws.\n", roll, dice, sides);
        for (i = 0; i < roll; i++)
        {
            printf("%5d ", roll_cases[i]);
            if (i % 10 == 9)
                printf("\n");
        }
        printf("\n");
        free(roll_cases);
        roll = input("Enter the number of sets; enter q to stop: ");
    }
    printf("\nGoodbye!\n");

    return 0;
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