#include <stdio.h>

void to_base_n(int, int);

int main(void)
{
    int num, base, status;

    printf("Enter tow positive numbers: ");
    status = scanf("%d %d", &num, &base);
    while (1)
    {
        if (status == 2)
        {   
            to_base_n(num, base);
            printf("\n");
            status = scanf("%d %d", &num, &base);
        }
        else
        {
            if (getchar() == 'q')
                break;
            printf("Enter two positive numbers again: ");
            while (getchar() != '\n')
                continue;
        }
    }
}

void to_base_n(int num, int base)
{
    int remainder, quot;

    remainder = num % base;
    quot = num / base;
    if (quot != 0)
        to_base_n(num / base, base);
    printf("%d", remainder);
}