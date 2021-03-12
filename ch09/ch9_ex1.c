#include <stdio.h>

double min(double, double);
int main(void)
{
    double x, y;

    while (scanf("%lf %lf", &x, &y) != 2)
    {
        printf("Invalid input. Input again: ");
    }
    printf("The smaller one is: %f\n", min(x, y));

    return 0;
}

double min(double x, double y)
{
    return (x > y) ? y : x;
}