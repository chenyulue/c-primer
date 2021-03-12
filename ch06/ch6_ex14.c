#include <stdio.h>
#define SIZE 8

int main(void)
{
    double fst_arr[SIZE], snd_arr[SIZE];
    int i;

    printf("Enter the eight numbers for the first array:\n");
    for (i = 0; i < SIZE; i++)
    {
        scanf("%lf", &fst_arr[i]);
        if (i==0)
            snd_arr[i] = fst_arr[i];
        else
            snd_arr[i] = snd_arr[i-1] + fst_arr[i];
    }
    for (i = 0; i < SIZE; i++)
        printf("%5.1f ", fst_arr[i]);
    printf("\n");
    for (i = 0; i < SIZE; i++)
        printf("%5.1f ", snd_arr[i]);
    printf("\n");

    return 0;
}