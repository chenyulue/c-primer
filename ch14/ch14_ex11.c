#include <stdio.h>
#include <math.h>
#include <string.h>

#define SIZE 10

void transform(const double source[], double target[], int sizeOfArray, double (*func)(double));
double func1(double);
double func2(double);

int main(void)
{
    double (*fun[4])(double) = {sin, sqrt, func1, func2};
    double arr[SIZE], arr1[SIZE];
    int i;
    char label[10];

    for (i = 0; i < SIZE; i++)
        arr[i] = i + 10;
    printf("The source array is:\n");
    for (i = 0; i < SIZE; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
    for (i = 0; i < 4; i++)
    {
        transform(arr, arr1, SIZE, fun[i]);
        if (i == 0)
            strcpy(label, "sin");
        else if (i == 1)
            strcpy(label, "sqrt");
        else if (i == 2)
            strcpy(label, "func1");
        else
            strcpy(label, "func2");
        printf(">>%s(arr) is:\n", label);
        for (int j = 0; j < SIZE; j++)
            printf("%.2f ", arr1[j]);
        printf("\n");
    }

    return 0;
}

void transform(const double source[], double target[], int sizeOfArray, double (*func)(double))
{
    int i;

    for (i = 0; i < sizeOfArray; i++)
        target[i] = func(source[i]);
}

double func1(double x)
{
    return 2*x;
}
double func2(double x)
{
    return pow(2, x);
}