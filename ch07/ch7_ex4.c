#include <stdio.h>

int main(void)
{
    char ch;
    int count;

    count = 0;
    while ((ch = getchar()) != '#')
    {
        if (ch == '.')
        {
            putchar('!');
            count++;
        } else if (ch == '!')
        {
            printf("!!");
            count++;
        } else
        {
            putchar(ch);
        }
    }
    printf("\n");
    printf("It has made %d substitutions.\n", count);

    return 0;
}