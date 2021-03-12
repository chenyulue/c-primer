#include <stdio.h>
#define SIZE 26

int main(void)
{
    char letter, alpha[SIZE];
    int i;

    for (i = 0, letter = 'a'; i < SIZE; i++, letter++)
    {
        alpha[i] = letter;
    }
    for (i = 0; i < SIZE; i++)
    {
        printf("%c", alpha[i]);
    }
    printf("\n");

    return 0;
}