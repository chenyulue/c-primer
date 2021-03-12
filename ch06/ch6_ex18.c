#include <stdio.h>
#define INITIAL_FRIENDS 5
#define DUNBAR_NUMBER 150

int main(void)
{
    int count, week;

    count = INITIAL_FRIENDS;
    week = 1;
    while (count <= DUNBAR_NUMBER)
    {
        count = 2 * (count - week);
        printf("Week %d => %d friends.\n", week, count);

        week++;
    }

    return 0;
    
}