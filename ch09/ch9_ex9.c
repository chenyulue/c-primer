#include <stdio.h>
#include <math.h>

double power(double, int);
double power_recursive(double, int);
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
    else if (exp >= 0)
        return power_recursive(base, exp);
    else
        return 1 / power_recursive(base, abs(exp));
}

double power_recursive(double base, int exp)
{
    double result = 1.0;
    double tmp;

    if (exp == 0)
        return result;
    else if (exp % 2 == 0)
    {
        tmp = power_recursive(base, exp / 2);
        return tmp * tmp;
    } else
    {
        return base * power_recursive(base, exp - 1);
    }
}