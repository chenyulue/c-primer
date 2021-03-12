#include <stdio.h>

const int DAYS_PER_WEEK = 7;

int main(void)
{
    int days;

    printf("Enter the number of days: ");
    scanf("%d", &days);
    while(days > 0)
    {
        printf("%d days are %d weeks, %d days.\n", 
               days, days / DAYS_PER_WEEK, days % DAYS_PER_WEEK);
        printf("Enter again? ");
        scanf("%d", &days);
    }
}