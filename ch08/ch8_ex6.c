#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main(void)
{
    int ch;

    while ((ch = get_first()) != EOF)
        printf("%c\n", ch);

    return 0;
}

char get_first(void)
{
    int ch;

    while (isspace(ch=getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    
    return ch;
}