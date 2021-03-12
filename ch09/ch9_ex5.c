#include <stdio.h>

void larger_of(double *, double *);

int main(void)
{
    double x, y;

    while (scanf("%lf %lf", &x, &y) != 2)
    {
        printf("Invalid inputs. Enter two floating numbers: ");
    }
    printf("The original x and y are %f and %f.\n", x, y);
    larger_of(&x, &y);
    printf("The replaced x and y are %f and %f.\n", x, y);

    return 0;
}

void larger_of(double * x, double * y)
{
    double tmp;

    tmp = (*x > *y) ? *x : *y;
    *x = tmp;
    *y = tmp;
}