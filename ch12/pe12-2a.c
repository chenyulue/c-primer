#include <stdio.h>
#define DISTANCE "Enter distance traveled in "
#define FUEL "Enter fuel consumed in "

int mode;
double distance;
double fuel;

void set_mode(int m)
{
    if ( m > 1)
        printf("Invalid mode specified. Mode %d(%s) used.\n", mode, mode ? "US" : "metric");
    else
        mode = m;
}

void get_info(void)
{
    if (mode)
    {
        printf(DISTANCE "miles: ");
        scanf("%lf", &distance);
        printf(FUEL "gallons: ");
        scanf("%lf", &fuel);
    } else
    {
        printf(DISTANCE "kilometers: ");
        scanf("%lf", &distance);
        printf(FUEL "liters: ");
        scanf("%lf", &fuel);
    }
}

void show_info(void)
{
    if (mode)
    {
        printf("Fuel consumption is %0.1f miles per gallon.\n", distance / fuel);
    } else
    {
        printf("Fuel consumption is %0.2f liters per 100 km.\n", fuel / distance * 100);
    }
}