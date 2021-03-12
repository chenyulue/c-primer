#include <stdio.h>
#include <ctype.h>

void rm_space(char * str);

int main(void)
{
    char line[40];

    printf("Input a line of string (an empty line to quit):\n");
    fgets(line, 40, stdin);
    //gets(line);
    while (line[0] != '\n')
    {
        rm_space(line);
        printf("Line witout spaces:\n\"%s\"\n", line);
        printf("Input again:\n");
        fgets(line, 40, stdin);
        //gets(line);
    }

    return 0;
}

void rm_space(char * str)
{
    char * replace;

    while (!isspace(*str) && *str != '\0')
            str++;
    if (*str == '\0')
    {
        return;
    }
    replace = str;

    while (*str != '\0')
    {
        if (isspace(*str))
        {
            str++;
            continue;
        }
        while (!isspace(*str) && *str != '\0')
        {
            *replace = *str;
            replace++;
            str++;
        }
        if (*str == '\0')
        {
            *replace = '\0';
            return;
        }
    }
    *replace = '\0';

}