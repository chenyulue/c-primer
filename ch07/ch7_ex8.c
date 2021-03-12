#include <stdio.h>
#define FIRST_PAY_RATE 8.75
#define SECOND_PAY_RATE 9.33
#define THIRD_PAY_RATE 10.0
#define FOURTH_PAY_RATE 11.2
#define BASIC_WORK_HOURS 40
#define FIRST_TAX_RATE 0.15
#define SECOND_TAX_RATE 0.2
#define THIRD_TAX_RATE 0.25
#define FIRST_PAY 300.0
#define SECOND_PAY (FIRST_PAY+150.0)
#define FIRST_TAX (300.0*FIRST_TAX_RATE)
#define SECOND_TAX (FIRST_TAX+150.0*SECOND_TAX_RATE)

int main(void)
{
    double pay, tax, rate, excess_rate;
    int hours;
    char choice;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr                   2) $9.33/hr\n");
    printf("3) $10.00/hr                  4) $11.20/hr\n");
    printf("5) quit\n");
    printf("*****************************************************************\n");
    printf("Enter your choice: ");
    while ((choice = getchar()) != '5')
    {
        if (choice == '\n')
            continue;
        switch (choice)
        {
            case '1': rate = FIRST_PAY_RATE;
                      break;
            case '2': rate = SECOND_PAY_RATE;
                      break;
            case '3': rate = THIRD_PAY_RATE;
                      break;
            case '4': rate = FOURTH_PAY_RATE;
                      break;
            default: printf("Only 1 to 5 are allowed.\n");
                     printf("Please re-enter: ");
                     continue;
        }
        excess_rate = 1.5 * rate;
        printf("Enter the hours worked in a week: ");
        scanf("%d", &hours);
        if (hours <= BASIC_WORK_HOURS)
        {
            pay = rate * (double)hours;
        } else
        {
            pay = rate * BASIC_WORK_HOURS + ((double)hours - BASIC_WORK_HOURS) * excess_rate;
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
        printf("  The gross pay: $%.2f\n", pay);
        printf("  the taxes: $%.2f\n", tax);
        printf("  The net pay: $%.2f\n", pay-tax);
        printf("Enter your choice: ");
    }

    return 0;
}