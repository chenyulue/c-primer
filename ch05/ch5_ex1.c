#include <stdio.h>
#define MIN_PER_HOUR 60

int main(void)
{
    int time;

    printf("Enter the time in minutes: ");
    scanf("%d", &time);
    while (time > 0)
    {
        printf("%d minutes are equal to %d hours and %d minutes\n",
               time, time/MIN_PER_HOUR, time%MIN_PER_HOUR);
        printf("Enter again: ");
        scanf("%d", &time);
    }

    return 0;
}