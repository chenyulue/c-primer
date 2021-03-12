#include <stdio.h>
#include <string.h>
#include "month.h"

static month_t months[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int main(void)
{
    char month[10];

    printf("Input the month: ");
    while (scanf("%s", month) == 1)
    {
        int total;

        if ((total = days(month)) > 0)
            printf("The total days up to %s are %d.\n", month, total);
        else
        {
            printf("Invalid month name.\nBye!");
            break;
        }
    }

    return 0;
}

int days(char * month)
{
    int total, index;

    for (index = 0, total = 0; strncmp(months[index].name, month, 3) != 0 && index < 12; index++)
        total += months[index].days;
    if (total == 365)
        return -1;
    return total + months[index].days;
}