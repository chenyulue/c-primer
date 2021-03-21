#include <stdio.h>
#include <stdbool.h>

#define SIZE 100000

bool binarySearch(int arr[], int num, int target);

int main(void)
{
    int arr[SIZE];
    int i, n;

    for (i = 0; i < SIZE; i++)
        arr[i] = i + 4;
    puts("Enter the number to search:");
    while (scanf("%d", &n) == 1)
    {
        if (binarySearch(arr, SIZE, n))
            printf("Find %d\n", n);
        else
            printf("Not find %d\n", n);
        puts("Enter another number to search:");
    }

    return 0;
}

bool binarySearch(int arr[], int num, int target)
{
    int start = 0;
    int end = num;
    int mid;

    while (start < end - 1)
    {
        mid = (start + end) / 2;
        if (target == arr[mid])
            return true;
        else if (target < arr[mid])
            end = mid;
        else
            start = mid;
    }
    return false;
}