#include <stdio.h>

int get_location(char);

int main(void)
{
    int ch, loc;

    while ((ch = getchar()) != EOF)
    {
        loc = get_location(ch);
        if (loc == -1 && ch != '\n')
            printf("'%c' is not a letter.\n", ch);
        else if (ch != '\n')
            printf("'%c' is a letter in %d position.\n", ch, loc+1);
    }

    return 0;
}

int get_location(char ch)
{
    if ('a' <= ch && ch <= 'z')
        return ch - 'a';
    else if ('A' <= ch && ch <= 'Z')
        return ch - 'A';
    else
        return -1;
}