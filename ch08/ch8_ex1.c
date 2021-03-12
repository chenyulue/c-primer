#include <stdio.h>

int main(void)
{
    int count, ch;

    count = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch != '\n')
            count++;
    }
    printf("The number of characters in the input is %d.\n", count);

    return 0;
}