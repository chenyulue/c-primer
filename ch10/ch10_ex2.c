#include <stdio.h>
void copy_arr(double t[], double s[], int num);
void copy_ptr(double *t, double *s, int num);
void copy_ptrs(double *t, double *s_start, double *s_end);
void display_arr(double [], int);

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    display_arr(source, 5);
    display_arr(target1, 5);
    display_arr(target2, 5);
    display_arr(target3, 5);
}

void copy_arr(double target[], double source[], int num)
{
    int i;
    
    for (i = 0; i < num; i++)
        target[i] = source[i];
}

void copy_ptr(double *target, double *source, int num)
{
    int i;

    for (i = 0; i < num; i++)
        *(target + i) = *(source + i);
}

void copy_ptrs(double *target, double *source_start, double *source_end)
{
    int i;

    i = 0;
    while ((source_start + i) < source_end)
    {
        *(target + i) = *(source_start + i);
        i++;
    }
}

void display_arr(double arr[], int num)
{
    int i;

    printf("Array at %p:\n", arr);
    for (i = 0; i < num; i++)
        printf("%.1f ", arr[i]);
    printf("\n");
}