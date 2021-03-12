#include <stdio.h>

int main(void)
{
    int divisor, dividend;

    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &divisor);
    printf("Now enter the first operand: ");
    scanf("%d", &dividend);
    while(dividend > 0)
    {
        printf("%d %% %d is %d\n", dividend, divisor, dividend % divisor);
        printf("Enter next number for first operand (<= 0 to quit): ");
        scanf("%d", &dividend);
    }
    printf("Done");

    return 0;
}