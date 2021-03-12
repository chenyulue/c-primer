#include <stdio.h>

double power(double, int);
int get_two_numbers(double *, int *);

int main(void)
{
    double base;
    int exp;

    while (get_two_numbers(&base, &exp) != -1)
    {
        printf("= %f\n", power(base, exp));
    }

    return 0;
}

int get_two_numbers(double * base, int * exp)
{
    int status;

    status = scanf("%lf ^ %d", base, exp);
    while (1)
    {
        if (getchar() == 'q')
            return -1;
        else if (status != 2)
        {
            printf("Enter again in the form of e.g. 3.4 ^ 6: \n");
            status = scanf("%lf ^ %d", base, exp);
            continue;
        }
        else
            return 1;
    }
}

double power(double base, int exp)
{
    double result = 1.0;
    int i;

    if (base == 0.0)
    {
        if (exp == 0)
        {   
            printf("0 ^ 0 is undefined, but the value of 1 is used.\n");
            return 1.0;
        }
        return 0.0;
    }
    else if (exp == 0)
        return 1.0;
    else if (exp > 0)
    {
        for (i = 0; i < exp; i++)
            result *= base;
    } else
    {
        for (i = exp; i < 0; i++)
        {
            result *= base;
        }
        result = 1/result;
    }

    return result;
}