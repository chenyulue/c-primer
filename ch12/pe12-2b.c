#include <stdio.h>
#define DISTANCE "Enter distance traveled in "
#define FUEL "Enter fuel consumed in "

void set_mode(int * m, int * c)
{
    if ( *c > 1)
        printf("Invalid mode specified. Mode %d(%s) used.\n", *m, *m ? "US" : "metric");
    else
        *m = *c;
}

void get_info(int * m, double * distance, double * fuel)
{
    if (*m)
    {
        printf(DISTANCE "miles: ");
        scanf("%lf", distance);
        printf(FUEL "gallons: ");
        scanf("%lf", fuel);
    } else
    {
        printf(DISTANCE "kilometers: ");
        scanf("%lf", distance);
        printf(FUEL "liters: ");
        scanf("%lf", fuel);
    }
}

void show_info(int * m, double * distance, double * fuel)
{
    if (*m)
    {
        printf("Fuel consumption is %0.1f miles per gallon.\n", *distance / *fuel);
    } else
    {
        printf("Fuel consumption is %0.2f liters per 100 km.\n", *fuel / *distance * 100);
    }
}