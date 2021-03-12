#include <stdio.h>

int maximum(const int arr[], int num);
int maximum_index(const int arr[], int num);

int main(void)
{
    int arr[5] = {3,2,5,6,9};

    printf("The maximum is %d\n", maximum(arr, 5));
    printf("The index for the maximum is %d\n", maximum_index(arr, 5));

    return 0;
}

int maximum(const int arr[], int num)
{
    int max, idx;

    max = arr[0];
    for (idx = 1; idx < num; idx++)
    {
        if (arr[idx] > max)
            max = arr[idx];
    }

    return max;
}

int maximum_index(const int *arr, int num)
{
    int max, idx, i;

    max = arr[0];
    idx = 0;
    for (i = 1; i < num; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            idx = i;
        }
    }

    return idx;
}