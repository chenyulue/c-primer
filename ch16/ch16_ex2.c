#include <stdio.h>
#include "ch16_ex1.h"

int main(void)
{
    double x, y;

    while (scanf("%lf %lf", &x, &y) == 2)
    {
        printf("The harmonic mean of %g and %g is %g\n", x, y, HMEAN(x, y));
    }

    return 0;
}