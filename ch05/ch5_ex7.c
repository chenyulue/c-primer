#include <stdio.h>

double cubed(double num);

int main(void)
{
    double num;

    printf("Enter a number: ");
    scanf("%lf", &num);
    printf("%f cubed is %f\n", num, cubed(num));

    return 0;
}

double cubed(double num)
{
    double result = num * num * num;
    return result;
}