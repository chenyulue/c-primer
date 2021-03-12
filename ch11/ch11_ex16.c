#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char * map(const char * fun, char * str);
void echo(const char *fun, char * line);

int main(int argc, char * argv[])
{
    char line[40];

    printf("Input a line of string: ");
    while (fgets(line, 40, stdin) != NULL)
    {
        if (argc < 2)
            printf("%s", map("", line));
        else if (strcmp(argv[1], "-p") == 0)
            printf("%s", map("", line));
        else if (strcmp(argv[1], "-u") == 0)
            printf("%s", map("toupper", line));
        else if (strcmp(argv[1], "-l") == 0)
            printf("%s", map("tolower", line));
        else
        {
            printf("Usage: %s -options\n", argv[0]);
            printf("Options:\n");
            printf("   -p     Print input as is.\n");
            printf("   -u     Map input to all uppercase.\n");
            printf("   -l     Map input to all lowercase\n");
            printf("default to -p.\n");
            exit(EXIT_FAILURE);
        }
        printf("Input a line of string: ");
    }
}

char * map(const char * fun, char * str)
{
    char * start;

    start = str;
    if (strcmp(fun, "tolower") == 0)
    {
        while (*str != '\0')
        {
            *str = tolower(*str);
            str++;
        }
    } else if (strcmp(fun, "toupper") == 0)
    {
        while (*str != '\0')
        {
            *str = toupper(*str);
            str++;
        }
    }

    return start;
}