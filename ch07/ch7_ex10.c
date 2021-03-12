#include <stdio.h>
#define BASIC_TAX_RATE 0.15
#define EXCESS_TAX_RATE 0.28
#define SINGLE 17850.0
#define HOUSEHOLD 23900.0
#define MARRIED_JOINT 29750.0
#define MARRIED_SEPARATE 14875.0

int main(void)
{
    char category;
    double base, income, tax;

    printf("*************************\n");
    printf("Specify the tax category:\n");
    printf("1) Single\n");
    printf("2) Head of Household\n");
    printf("3) Married, Joint\n");
    printf("4) Married, Separate\n");
    printf("5) quit\n");
    printf("Your choice: ");
    while ((category = getchar()) != '5')
    {
        while (getchar() != '\n')
            continue;
        switch (category)
        {
            case '1': base = SINGLE;
                      break;
            case '2': base = HOUSEHOLD;
                      break;
            case '3': base = MARRIED_JOINT;
                      break;
            case '4': base = MARRIED_SEPARATE;
                      break;
            default: printf("Only 1 to 5 are allowed. Re-enter: ");
                     continue;
        }
        printf("Enter the taxable income ($): ");
        while (scanf("%lf", &income) != 1)
        {
            printf("Invalid input. Please re-enter: ");
        }
        if (income <= base)
        {
            tax = income * BASIC_TAX_RATE;
        } else
        {
            tax = base * BASIC_TAX_RATE + (income - base) * EXCESS_TAX_RATE;
        }
        printf("The tax in your choice is $%.2f, with the "
               "taxable income of $%.2f.\n", tax, income);
        while (getchar() != '\n')
            continue;
        printf("\nYour new choice: ");
    }
}