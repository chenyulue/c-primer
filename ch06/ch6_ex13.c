#include <stdio.h>
#define SIZE 8

int main(void)
{
    int arr[SIZE], i;

    for (i = 1, arr[0]=2; i < SIZE; i++)
        arr[i] = arr[i-1]*2;
    i = 0;
    do
    {
        printf("%d\n", arr[i]);
    } while (++i < SIZE);
    
    return 0;
}