#include <stdio.h>
#include <ctype.h>

int get_word(char * word, int max);

int main(void)
{
    char str[40];

    printf("Input a string: ");
    while (get_word(str, 9) != EOF)
    {
        printf("The word fetched is \"%s\".\n", str);
        printf("Input a string: ");
    }

    return 0;
}

int get_word(char * word, int max)
{
    int ch, i;

    i = 0;
    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch))
        {
            word[i] = ch;
            i++;
            if (i == max)
            {
                while (getchar() != '\n')
                    continue;
                word[i] = '\0';
                return 1;
            }
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