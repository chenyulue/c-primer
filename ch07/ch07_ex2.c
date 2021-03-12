#include <stdio.h>

int main(void)
{
    int count;
    char ch;

    count = 1;
    while ((ch = getchar()) != '#')
    {
        printf("%c=>%d ", ch, ch);
        if (count % 8 == 0)
        {
            printf("\n");
        }
        count++;
    }
    printf("Done!\n");

    return 0;
}