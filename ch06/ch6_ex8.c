#include <stdio.h>

int main(void)
{
    float first, second;

    printf("Enter a pair of numbers: ");
    while (scanf("%f %f", &first, &second) == 2)
    {
        printf("%f\n", (first - second) / (first * second));
        printf("Enter next pair of numbers: ");
    }
    
}