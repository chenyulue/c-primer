#include <stdio.h>

int main(void)
{
    int count, sum, days;

    count = 0;
    sum = 0;
    printf("How far the calculation should proceed? ");
    scanf("%d", &days);
    while(count++ < days)
    {
        sum = sum + count * count;
    }
    printf("sum = %d\n", sum);

    return 0;
}