#include <stdio.h>

int main(void)
{
    char row, col, letter, tmp;

    printf("Enter  letter: ");
    for (row = 'A', scanf("%c", &letter); row <= letter; row++)
    {
        tmp = letter;
        for (col = row; col < letter; col++)
            printf(" ");
        for (col = 'A'; col <= row; col++)
            printf("%c", col);
        for (col = row-1; col >= 'A'; col--)
            printf("%c", col);
        printf("\n");
    }

    return 0;
}