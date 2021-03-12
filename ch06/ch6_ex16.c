#include <stdio.h>
#define INVEST 100

int main(void)
{
    double money_simple, money_compound;
    int year;

    money_simple = money_compound = INVEST;
    for ( year = 0; money_compound <= money_simple; year++)
    {
        money_compound += money_compound * 0.05;
        money_simple += INVEST * 0.1;
    }
    printf("After %d years, Deirdre will get $%.2f, \n", year, money_compound);
    printf("more than Daphne who will get $%.2f.\n", money_simple);

    return 0;
    
}