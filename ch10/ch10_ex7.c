#include <stdio.h>

void copy_arr(double t[], const double s[], int num);
void display_arr(double [], int);

int main(void)
{
    double source[3][5] = 
    {
        {3.4, 5.6, 2.5, 4.7, 2.5},
        {1.5, 7.4, 9.4, 0.5, 3.2},
        {5.3, 0.1, 8.8, 3.4, 2.2}
    };
    double target[3][5];
    int i;
    double s[7] = {1,2,3,4,5,6,7};
    double t[3];

    printf("Source at %p:\n", source);
    for (i = 0; i < 3; i++)
        display_arr(source[i], 5);
    for (i = 0; i < 3; i++)
        copy_arr(target[i], source[i], 5);
    printf("Target at %p:\n", target);
    for (i = 0; i < 3; i++)
        display_arr(target[i], 5);
    
    printf("Source at %p:\n", s);
    display_arr(s, 7);
    copy_arr(t, s+2, 3);
    printf("Target at %p:\n", t);
    display_arr(t, 3);

}

void copy_arr(double target[], const double source[], int num)
{
    int i;
    
    for (i = 0; i < num; i++)
        target[i] = source[i];
}

void display_arr(double arr[], int num)
{
    int i;

    for (i = 0; i < num; i++)
        printf("%.1f ", arr[i]);
    printf("\n");
}