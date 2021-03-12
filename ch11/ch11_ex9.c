#include <stdio.h>
#include <string.h>

void rstr(char * str);

int main(void)
{
    char str[40];

    printf("Input a string: ");
    while (scanf("%39s", str) == 1)
    {
        printf("Read string is \"%s\".\n", str);
        rstr(str);
        printf("Reversed string is \"%s\".\n", str);
    }

    return 0;
}

void rstr(char * str)
{
    size_t n = strlen(str);
    char * end;
    char tmp;

    for (end = str + n - 1; str < end; str++, end--)
    {
        tmp = *str;
        *str = *end;
        *end = tmp;
    }
}