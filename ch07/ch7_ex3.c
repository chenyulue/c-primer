#include <stdio.h>

int main(void)
{
    int evens, odds, num, even_total, odd_total;
    float even_avg, odd_avg;

    evens = odds = even_total = odd_total = 0;
    printf("Enter any number of integers (0 to finished):\n");
    scanf("%d", &num);
    while (num != 0)
    {
        if (num % 2 == 0)
        {
            evens++;
            even_total += num;
        } else
        {
            odds++;
            odd_total += num;
        }
        scanf("%d", &num);
    }
    even_avg = (float)even_total / evens;
    odd_avg = (float)odd_total / odds;
    printf("total number of even integers: %d\n", evens);
    printf("average value of the even integers: %.4f\n", even_avg);
    printf("total number of odd integers: %d\n", odds);
    printf("average value of the odd integers: %.4f\n", odd_avg);

    return 0;
}