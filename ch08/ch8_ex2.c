#include <stdio.h>

int main(void)
{
    int ch, count;

    count = 0;
    printf("Enter a string of input:\n");
    while((ch = getchar()) != EOF)
    {
        if (ch < 32)
        {
            if (ch == '\n')
            {
                printf("\\n => %d, \n", ch);
                count = 0;
                continue;
            }
            else if (ch == '\t')
                printf("\\t => %d, ", ch);
            else
                printf("^%c => %d, ", ch+64, ch);
            count++;
        } else if (ch < 127)
        {
            printf("'%c' => %d, ", ch, ch);
            count++;
        } else
        {
            printf("^%c => %d, ", ch-64, ch);
            count++;
        }
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }

    return 0;
}