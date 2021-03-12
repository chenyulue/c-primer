#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int bstoi(char * pbin);
char * itobs(int num, char * ps);

int main(int argc, char * argv[])
{
    int num1, num2;
    const static int size = CHAR_BIT * sizeof(int);
    char ps[size];

    if (argc != 3)
    {
        printf("Usage: %s binaryString binaryString\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    num1 = bstoi(argv[1]);
    num2 = bstoi(argv[2]);
    printf("num1 = %d\nnum2 = %d\n", num1, num2);
    printf("~num1 = %s\n", itobs(~num1, ps));
    printf("~num2 = %s\n", itobs(~num2, ps));
    printf("num1 & num2 = %s\n", itobs(num1 & num2, ps));
    printf("num1 | num2 = %s\n", itobs(num1 | num2, ps));
    printf("num1 ^ num2 = %s\n", itobs(num1 ^ num2, ps));

    return 0;
}

int bstoi(char * pbin)
{
    int result;

    for (result = 0; *pbin; pbin++)
    {
        result = result * 2 + (*pbin - '0');
    }

    return result;
}

char * itobs(int num, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; i--, num >>= 1)
        ps[i] = (01 & num) + '0';
    ps[size] = '\0';

    return ps;
}