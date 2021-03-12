#include <stdio.h>

double harmonic_mean(double, double);

int main(void)
{
    double x, y;

    while (scanf("%lf %lf", &x, &y) != 2)
    {
        printf("Invalid inputs. Enter two float numbers: ");
    }
    printf("The harmonic mean of %0.2f and %0.2f is %0.2f\n", 
           x, y, harmonic_mean(x, y));

    return 0;
}

double harmonic_mean(double x, double y)
{
    double result;

    result = 1 / ((1/x + 1/y) / 2);

    return result;
}