#include <stdio.h>
#include <stdlib.h>
#include "ch16_ex1.h"

#define SIZE 10
#define N 8

int main(void)
{
    const int arr[SIZE] = {1,2,3,4,5,6,7,8,9,10};

    choice(arr, SIZE, N);

    return 0;
}

void choice (const int arr[], size_t size, int n)
{
    int * tmparr;
    int index, count;

    tmparr = (int *)calloc(size, sizeof (int));
    count = 0;
    srand((unsigned int) time(0));
    while (1)
    {
        index = rand() % size;
        if (tmparr[index])
            continue; 
        printf("%d ", arr[index]);
        tmparr[index] = 1;
        count++;
        if (count == n)
            break;
    }
    free(tmparr);
}