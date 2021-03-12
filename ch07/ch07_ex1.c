#include <stdio.h>

int main(void)
{
    char ch;
    int num_space, num_newline, num_other;

    num_space = num_newline = num_other = 0;
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            num_space++;
        else if (ch == '\n')
            num_newline++;
        else
            num_other++;
    }
    printf("%d spaces, %d newline characters, and %d other characters.\n",
           num_space, num_newline, num_other);

    return 0;
}