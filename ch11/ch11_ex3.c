#include <stdio.h>
#include <ctype.h>

int get_word(char * word);

int main(void)
{
    char str[40];

    printf("Input a string: ");
    while (get_word(str) != EOF)
    {
        printf("The word fetched is \"%s\".\n", str);
        printf("Input a string: ");
    }

    return 0;
}

int get_word(char * word)
{
    int ch, i;

    i = 0;
    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch))
        {
            word[i] = ch;
            i++;
        } else if (i != 0)
        {
            while (getchar() != '\n')
                continue;
            word[i] = '\0';
            return 1;
        }
    }
    return EOF;
}