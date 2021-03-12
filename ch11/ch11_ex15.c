#include <stdio.h>
#include <ctype.h>

int myatoi(const char *str);
int int_pow(int base, int exp);

int main(void)
{
    char str[40];

    printf("Input a string: ");
    while (scanf("%s", str))
    {
        while (getchar() != '\n')
            continue;
        printf("Read integer is: %d\n", myatoi(str));
        printf("Input again: ");
    }

    return 0;
}

int myatoi(const char *str)
{
    int num, count;

    count = 0;
    num = 0;
    while (*str != '\0' && isdigit(*str))
    {
        switch(*str)
        {
            case '0': num = num * 10 + 0;
                      break;
            case '1': num = num * 10 + 1;
                      break;
            case '2': num = num * 10 + 2;
                      break;
            case '3': num = num * 10 + 3;
                      break;
            case '4': num = num * 10 + 4;
                      break;
            case '5': num = num * 10 + 5;
                      break;
            case '6': num = num * 10 + 6;
                      break;
            case '7': num = num * 10 + 7;
                      break;
            case '8': num = num * 10 + 8;
                      break;
            case '9': num = num * 10 + 9;
        }
        count++;
        str++;
    }
    if (*str == '\0')
        return num;
    return 0;
}