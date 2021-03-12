#include <stdio.h>

void sort(double *, double *, double *);

int main(void)
{
    double x, y, z;

    while (scanf("%lf %lf %lf", &x, &y, &z) != 3)
    {
        printf("Invalid inputs. Enter three floating numbers: ");
        while (getchar() != '\n')
            continue;
    }
    printf("The original x, y and z are %f, %f, %f.\n", x, y, z);
    sort(&x, &y, &z);
    printf("The sorted x, y, and z are %f, %f, %f.\n", x, y, z);

    return 0;
}

void sort(double * x, double * y, double * z)
{
    double tmp;

    if (*x > *y)
    {
        tmp = *y;
        *y = *x;
        *x = tmp;
    }
    if (*z < *x)
    {
        tmp = *z;
        *z = *y;
        *y = *x;
        *x = tmp;
    } else if (*z < *y)
    {
        tmp = *z;
        *z = *y;
        *y = tmp;
    }
}