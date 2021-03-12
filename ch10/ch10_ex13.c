#include <stdio.h>
#define ROWS 3
#define COLS 5

void read_arr(int row, int col, double arr[row][col]);
void show_arr(int row, int col, const double arr[row][col]);
double row_average(const double arr[], int num);
double arr_average(int row, int col, const double arr[row][col]);
double find_largest(int row, int col, const double arr[row][col]);

int main(void)
{
    int row=ROWS, col=COLS;
    int i, j;
    double arr[row][col];

    read_arr(row, col, arr);
    printf("The array is:\n");
    show_arr(row, col, arr);
    printf("First compute the average of each set of five values:\n");
    for (i = 0; i < row; i++)
        printf("Set %d's average is %.2f\n", i+1, row_average(arr[i], col));
    printf("\nNext compute the average of all the values: %.2f\n", arr_average(row, col, arr));
    printf("\nFinaly find the largest value of the 15 values: %.2f\n", find_largest(row, col, arr));

    return 0;    
}

void read_arr(int row, int col, double arr[row][col])
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
            scanf("%lf", &arr[i][j]);
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

double row_average(const double arr[], int num)
{
    int i;
    double total;

    for (i = 0, total = 0; i < num; i++)
        total += arr[i];
    
    return total / num;
}

double arr_average(int row, int col, const double arr[row][col])
{
    int i;
    double total;

    for (i = 0, total = 0; i < row; i++)
        total += row_average(arr[i], col);
    
    return total / row;
}

double find_largest(int row, int col, const double arr[row][col])
{
    int i, j;
    double max = arr[0][0];

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }

    return max;
}