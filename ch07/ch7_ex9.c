#include <stdio.h>

_Bool isprime(int num);

int main(void)
{
    int status, idx, upper;

    printf("Enter a positive integer: ");
    status = scanf("%d", &upper);
    while (upper > 0 && status == 1)
    {
        printf("All the prime numbers below %d are:\n", upper);
        for (idx = 2; idx <= upper; idx++)
        {
            if (isprime(idx))
                printf("%d ", idx);
        }
        printf("\n");
        printf("Enter again? ");
        status = scanf("%d", &upper);
    }
}

_Bool isprime(int num)
{
    int idx;
    for (idx = 2; idx*idx <= num; idx++)
    {
        if (num % idx == 0)
            return 0;
    }
    return 1;
}