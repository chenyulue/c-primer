#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRLEN 10
#define TIMES 100000

int main(void)
{
    int arr[ARRLEN] = {0};
    int i, num;

    srand((unsigned int) time(0));
    for (i = 0; i < TIMES; i++)
    {
        num = rand() % 10;
        arr[num]++;
    }
    for (i = 0; i < ARRLEN; i++)
    {
        printf("Number of %d: %d\n", i+1, arr[i]);
    }

    return 0;

}