#include <stdio.h>

void reverse(double [], int);
void display_arr(const double [], int);

int main(void)
{
    double arr[6] = {1.3, 2.4, 7.4, 0.4, 3.4, 5.6};

    display_arr(arr, 6);
    reverse(arr, 6);
    display_arr(arr, 6);
}

void reverse(double arr[], int num)
{
    int start, end;
    double tmp;

    for (start = 0, end = num - 1; start < end; start++, end--)
    {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
    }
}

void display_arr(const double arr[], int num)
{
    printf("The array at %p:\n", arr);
    for (int i = 0; i < num; i++)
        printf("%.1f ", arr[i]);
    printf("\n");
}