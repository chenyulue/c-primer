#include <stdio.h>

int main(void)
{
    int count;
    char ch;

    count = 0;
    while (count < 10)
    {
        ch = getchar();
        if (ch == '\n')
            continue;
        putchar(ch);
        count++;
    }

    for (count = 0; count < 10; count++)
    {
        ch = getchar();
        if (ch == '\n')
            continue;
        putchar(ch);
    }

    return 0;
}