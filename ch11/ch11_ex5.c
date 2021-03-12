#include <stdio.h>

char * strchar(const char * source, char target);

int main(void)
{
    char ch, str[40];

    printf("Input a string and a char: ");
    while (scanf("%s %c", str, &ch) == 2)
    {
        printf("Found '%c' in \"%s\" at \"%s\".\n", ch, str, strchar(str, ch));
        printf("Input a string and a char: ");
    }

    return 0;
}

char * strchar(const char * source, char target)
{
    while (*source != target)
    {    
        source++;
        if (*source == '\0')
            return NULL;
    }
    return (char *) source;
}