#include <stdio.h>
#define SIZE 8

int main(void)
{
    int arr[SIZE], i;

    for (i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);
    for (i = SIZE-1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}