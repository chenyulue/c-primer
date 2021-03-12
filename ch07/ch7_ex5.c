#include <stdio.h>

int main(void)
{
    int count;
    char ch;

    count = 0;
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
        case '.':
            putchar('!');
            count++;
            break;
        case '!':
            printf("!!");
            count++;
            break;
        default:
            putchar(ch);
        }
    }
    printf("\n");
    printf("It has made %d substitutions.\n", count);

    return 0;
}