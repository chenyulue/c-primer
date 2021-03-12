#include <stdio.h>
#include <limits.h>

int count_on(int n);

int main(void)
{
    int num;

    while (scanf("%d", &num) == 1)
    {
        printf("The number of \"on\" bits is %d.\n", count_on(num));
    }

    return 0;
}

int count_on(int n)
{
    int result, i;
    const static int size = CHAR_BIT * sizeof (int);

    for (i = size - 1, result = 0; i >= 0; i--, n >>= 1)
    {
        if ((01 & n) == 1)
            result++;
    }

    return result;
}