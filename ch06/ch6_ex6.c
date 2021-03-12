#include <stdio.h>

int power(int base, int exp);
int main(void)
{
    int lower, upper, row, col;

    printf("Enter the lower and upper limits for the table: ");
    scanf("%d %d", &lower, &upper);
    printf("%8s %8s %8s\n", "num", "square", "cube");
    for (row = lower; row <= upper; row++)
    {
        for (col = 1; col <= 3; col++)
            printf("%8d ", power(row, col));
        printf("\n");
    }

    return 0;
}

int power(int base, int exp)
{
    int result = 1;

    for (int i = 0; i < exp; i++)
        result *= base;
    
    return result;
}