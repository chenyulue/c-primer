#include <stdio.h>

int main(void)
{
    int num;
    int i = -1;

    printf("Enter a number: ");
    scanf("%d", &num);
    while(++i <= 10)
    {
        printf("%d\n", num+i);
    }

    return 0;
}