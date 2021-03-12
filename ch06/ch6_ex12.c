#include <stdio.h>

int main(void)
{
    int limit, i;
    double sum;

    printf("Enter a limit: ");
    scanf("%d", &limit);
    for (i = 1, sum = 0.f; i <= limit; i++)
        sum += 1.0 / i;
    printf("The sum of the first series is %f\n", sum);
    for (i = 1, sum = 0.f; i <= limit; i += 2)
        sum += 1.0 / i;
    for (i = 2; i <= limit; i += 2)
        sum -= 1.0 / i;
    printf("The sum of the second series is %f\n", sum);

    return 0;
}