#include <stdio.h>

int called(void);

int main(void)
{
    while (getchar() == '\n')
        printf("Called %d times.\n", called());

    return 0;
}

int called(void)
{
    static int num = 0;

    return ++num;
}