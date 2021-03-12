#include <stdio.h>
#define BASIC_WORK_HOURS 40
#define BASIC_PAY_RATE 10.0
#define EXCESS_PAY_RATE (1.5*BASIC_PAY_RATE)
#define FIRST_TAX_RATE 0.15
#define SECOND_TAX_RATE 0.2
#define THIRD_TAX_RATE 0.25
#define FIRST_PAY 300.0
#define SECOND_PAY (FIRST_PAY+150.0)
#define FIRST_TAX (300.0*FIRST_TAX_RATE)
#define SECOND_TAX (FIRST_TAX+150.0*SECOND_TAX_RATE)

int main(void)
{
    double pay, tax;
    int hours;

    printf("Enter the hours worked in a week: ");
    scanf("%d", &hours);
    if (hours <= BASIC_WORK_HOURS)
    {
        pay = BASIC_PAY_RATE * (double)hours;
    } else
    {
        pay = BASIC_PAY_RATE * BASIC_WORK_HOURS + ((double)hours - BASIC_WORK_HOURS) * EXCESS_PAY_RATE;
    }
    if (pay <= FIRST_PAY)
    {
        tax = pay * FIRST_TAX_RATE;
    } else if (pay <= SECOND_PAY)
    {
        tax = FIRST_TAX + (pay - FIRST_PAY) * SECOND_TAX_RATE;
    } else
    {
        tax = SECOND_TAX + (pay - SECOND_PAY) * THIRD_TAX_RATE;
    }
    printf("\tThe gross pay: %.2f\n", pay);
    printf("\tthe taxes: %.2f\n", tax);
    printf("\tThe net pay: %.2f\n", pay-tax);

    return 0;
}