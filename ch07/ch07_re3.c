#include <stdio.h>

int main(void)
{
    int weight, height;

    scanf("%d %d", &weight, &height);
    if (weight < 100 && height >= 72)
    {
        printf("You are very tall for your weight.\n");
    } else if (weight < 100 && height > 64)
    {
        printf("You are tall for your weight.\n");
    } else if (weight > 300 && height < 48)
    {
        printf("You are quite short for your weight.\n");
    } else
    {
        printf("Your weight is ideal.\n");
    }

    return 0;
}