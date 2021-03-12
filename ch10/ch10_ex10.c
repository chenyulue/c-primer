#include <stdio.h>

void add(const int source1[], const int source2[], int target[], int num);
void display_arr(const int arr[], int num);

int main(void)
{
    int s1[4] = {2,4,5,8};
    int s2[4] = {1,0,4,6};
    int t[4];

    printf("S1 at %p\n", s1);
    display_arr(s1, 4);
    printf("S2 at %p\n", s2);
    display_arr(s2, 4);
    add(s1, s2, t, 4);
    printf("T at %p\n", t);
    display_arr(t, 4);    

    return 0;
}

void display_arr(const int arr[], int num)
{
    int i;

    for (i = 0; i < num; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void add(const int source1[], const int source2[], int target[], int num)
{
    int i;

    for (i = 0; i < num; i++)
        target[i] = source1[i] + source2[i];
}