#include <stdio.h>
void show_arr(const int arr[][5], int row);
void double_arr(int arr[][5], int row);

int main(void)
{
    int arr[3][5] = 
    {
        {11,12,13,14,15},
        {21,22,23,24,25},
        {31,32,33,34,35}
    };
    int i, j;

    printf("Original array:\n");
    show_arr(arr, 3);
    double_arr(arr, 3);
    printf("Doubled array:\n");
    show_arr(arr, 3);

    return 0;
}

void show_arr(const int arr[][5], int row)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void double_arr(int arr[][5], int row)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < 5; j++)
            arr[i][j] = arr[i][j]*2;
    }
}