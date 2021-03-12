#include <stdio.h>

unsigned long fib(unsigned long);

int main(void)
{
    unsigned long num;
    int status;

    status = scanf("%lu", &num);
    while (1)
    {
        if (status == 1)
        {
            printf("fib(%lu) = %lu\n", num, fib(num));
            status = scanf("%lu", &num);
        } else if (getchar() == 'q')
            break;
        else
        {
            printf("Enter an integer please: ");
            status = scanf("%lu", &num);
        }
    }
}

unsigned long fib(unsigned long num)
{
    unsigned long result, pre, current, i, tmp;

    current = 1;
    pre = 0;
    for (i = 0; i < num; i++)
    {
        tmp = current;
        current = current + pre;
        pre = tmp;
    }

    return current;
}