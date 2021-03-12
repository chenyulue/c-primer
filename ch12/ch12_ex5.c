#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRSIZE 100

void sort(int arr[], int num);
int main(void)
{
    int randarr[ARRSIZE];
    int i;

    srand((unsigned int)time(0));
    for (i = 0; i < ARRSIZE; i++)
        randarr[i] = rand() % 10 + 1;
    sort(randarr, ARRSIZE);
    for (i = 0; i < ARRSIZE; i++)
        printf("%d ", randarr[i]);
    printf("\n");

    return 0;
}

void sort(int arr[], int num)
{
    int tmp, i, j;

    for (i = 0; i < num; i++)
    {
        for (j = i+1; j < num; j++)
        {
            if (arr[i] < arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}