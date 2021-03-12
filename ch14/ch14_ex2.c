#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct month {
    char name[10];
    char abbrv[4];
    int days;
    int monthnum;
} month_t;

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

bool isleapyear(int year);
int days(int day, char * month, int year);

int main(void)
{
    int day, year;
    char month[10];

    printf("Enter the day, month and year by order:\n");
    while (scanf("%d %s %d", &day, month, &year) == 3)
    {
        int total;

        total = days(day, month, year);
        if (total < 0)
            break;
        printf("The total days up to %d-%s-%d are %d.\n", 
               day, month, year, total);
        printf("Enter the day, month and year by order:\n");
    }
    printf("Invalid input.\nBye!\n");

    return 0;
}

bool isleapyear(int year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 != 0 && year % 4 == 0)
        return true;
    else
        return false;
}

int days(int day, char * month, int year)
{
    int monthnum, index, total;
    char * end;

    monthnum = strtol(month, &end, 10);
    if (*end == '\0')
    {
        if (monthnum < 1 && monthnum > 12)
            return -1;
        else if (isleapyear(year) && monthnum == 2 && day > 29)
            return -1;
        else if (day > months[monthnum-1].days)
            return -1;
        else
        {
            for (index = 0, total = 0; index < monthnum-1; index++)
                total += months[index].days;
        }
    }  else if (*end == month[0])
    {
        if (strncmp(month, "Feb", 3) == 0 && day > (isleapyear(year)? 29 : 28))
            return -1;
        else if (!(strncmp(month, "Jan", 3) && strncmp(month, "Mar", 3) && strncmp(month, "May", 3) && 
                   strncmp(month, "Jul", 3) && strncmp(month, "Aug", 3) && strncmp(month, "Oct", 3) && strncmp(month, "Dec", 3))
                 && day > 31)
            return -1;
        else if (!(strncmp(month, "Apr", 3) && strncmp(month, "Jun", 3) && strncmp(month, "Sep", 3) && strncmp(month, "Nov", 3))
                 && day > 30)
            return -1;
        else
            for (index = 0, total = 0; strncmp(months[index].name, month, 3) != 0 && index < 12; index++)
                total += months[index].days;
        if (total == 365)
            return -1;
    }
    total += day;
    if (monthnum > 2 && isleapyear(year))
        total++;
    return total;
}
