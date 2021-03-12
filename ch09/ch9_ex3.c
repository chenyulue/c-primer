#include <stdio.h>

void print_table(char, int, int);

int main(void)
{
    char ch;
    int row, col, idx;

    printf("Enter a character: ");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    printf("Enter the row and column numbers: ");
    while (scanf("%d %d", &row, &col) != 2)
    {
        printf("Invalid input. Enter two integers: ");
    }
    print_table(ch, col, row);
    
    return 0;
}

void print_table(char ch, int col, int row)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            putchar(ch);
        printf("\n");
    }
}