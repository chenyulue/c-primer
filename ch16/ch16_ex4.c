#include <stdio.h>
#include <time.h>
#include "ch16_ex1.h"

int main(void)
{
    double time;
    clock_t start;

    while (scanf("%lf", &time) == 1)
    {
        start = clock();
        while (delay(time, &start))
            continue;
        printf("%g seconds elapsed.\n", time);
    }

    return 0;
}

bool delay(double time, const clock_t * start)
{
    clock_t end = clock();

    if ((double)(end - *start)/CLOCKS_PER_SEC == time)
        return 0;
    return 1;
}