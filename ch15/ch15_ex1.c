#include <stdio.h>
#include <string.h>

int btod(char * pbin);

int main(void)
{
    char pbin[40];

    printf("Enter the binary string: ");
    while (fgets(pbin, 40, stdin) != NULL)
    {
        char * find = strchr(pbin, '\n');
        if (find)
            *find = '\0';
        printf("0b%s = %d\n", pbin, btod(pbin));
        printf("Enter the binary string: ");
    }

    return 0;
}

int btod(char * pbin)
{
    int result;

    for (result = 0; *pbin; pbin++)
    {
        result = result * 2 + (*pbin - '0');
    }

    return result;
}