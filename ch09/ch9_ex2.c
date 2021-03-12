#include <stdio.h>

void chline(char, int, int);

int main(void)
{
    char ch;
    int i, j;

    printf("Enter a character: ");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    printf("Enter the lower and upper limits of columns: ");
    while (scanf("%d %d", &i, &j) != 2)
    {
        printf("Invalid input. Enter two integers: ");
    }
    chline(ch, i, j);
    
    return 0;
}

void chline(char ch, int i, int j)
{
    int idx;

    for (idx = 0; idx < i; idx++)
        putchar(' ');
    for (idx = i; idx < j; idx++)
        putchar(ch);
}