#include <stdio.h>

int is_within(char ch, char * str);

int main(void)
{
    char ch, str[40];
    int count;

    printf("Input a string and a char: ");
    while (scanf("%39s %c", str, &ch) == 2)
    {
        count = is_within(ch, str);
        if (count)
            printf("Found %d '%c'(s) in \"%s\".\n", count, ch, str);
        else
            printf("Not found '%c' in \"%s\".\n", ch, str);
    }

    return 0;
}

int is_within(char ch, char * str)
{
    int count = 0;

    while (*str != '\0')
    {
        if (*str == ch)
            count++;
        str++;
    }

    return count;
}