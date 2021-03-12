#include <stdio.h>
#define MONEY 1000000.0
#define WITHDRAW 100000.0

int main(void)
{
    int year;
    double money;

    money = MONEY;
    year = 0;
    while (money >= 100000)
    {
        money += money * 0.08 - WITHDRAW;
        year++;
        printf("After %d year(s), $%.2f is left.\n", year, money);
    }
    printf("After %d years, Chuckie will empty his count, with $%.2f left.\n", year, money);

    return 0;
    
}