#include <stdio.h>

double difference(const double [], int);

int main(void)
{
    double arr[7] = {1.3, 4.2, 0.4, 3.2, 6.7, 2.3, 1.7};

    printf("The difference between the largest and smallest elements is %.1f\n",
           difference(arr, 7));
    
    return 0;
}

double difference(const double arr[], int num)
{
    double min, max;
    int i;

    min = max = arr[0];
    for (i = 1; i < num; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    return max - min;
}