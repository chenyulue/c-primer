#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gets_n(char * str, int n);

int main(void)
{
    char str[40];
    int n;

    while (1)
    {
        int i;
        printf("How many characters do you want to fetch (0 to quit) ? ");
        while (scanf("%d", &n) != 1)
        {
            char ch_inner;
            while ((ch_inner = getchar()) != '\n')
                putchar(ch_inner);
            printf(" is not an integer. Input again: ");
        }
        while (getchar() != '\n')
            continue;
        if (n == 0)
            break;
        printf("Input a string: \n");
        if (gets_n(str, n) == EOF)
            break;
        printf("The string fetched is \"%s\" with %zd characters.\n", str, strlen(str));
        while (getchar() != '\n')
            continue;
    }

    return 0;
}

int gets_n(char * str, int n)
{
    int i, count, tmp;

    for (i = 0, count = 0; i < n; i++)
    {
        tmp = getchar();
        if (tmp == EOF)
            return EOF;
        else if (isspace(tmp))
            break;
        str[i] = tmp;
        count++;
    }
    str[i] = '\0';

    return count;
}