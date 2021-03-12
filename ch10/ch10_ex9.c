#include <stdio.h>

void copy_arr(int row, int col, double target[row][col], const double source[row][col]);
void show_arr(int row, int col, const double arr[row][col]);

int main(void)
{
    double source[3][5] = 
    {
        {1.1, 1.2, 1.3, 1.4, 1.5},
        {2.1, 2.2, 2.3, 2.4, 2.5},
        {3.1, 3.2, 3.3, 3.4, 3.5}
    };
    double target[3][5];

    printf("Source at %p:\n", source);
    show_arr(3, 5, source);
    copy_arr(3, 5, target, source);
    printf("Target at %p:\n", target);
    show_arr(3, 5, target);
}

void copy_arr(int row, int col, double target[row][col], const double source[row][col])
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            target[i][j] = source[i][j];
        }
    }
}

void show_arr(int row, int col, const double arr[row][col])
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            printf("%.1f ", arr[i][j]);
        printf("\n");
    }
}