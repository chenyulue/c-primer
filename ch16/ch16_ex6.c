#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ch16_ex1.h"

#define NUM 10
void showarray(const Name ar[], int n);
int mycomp(const void * pn1, const void * pn2);

int main(void)
{
    Name vals[NUM] = {
        {"Tom", "Smith"},
        {"John", "Byden"},
        {"Rudy", "Van"},
        {"Julia", "Carpenter"},
        {"Lily", "Author"},
        {"Kate", "Elitherbeth"},
        {"Andy", "Smith"},
        {"Tom", "Bush"},
        {"Zhenyu", "Lue"},
        {"Tompson", "Luke"}
    };

    puts("Original names: \n");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(Name), mycomp);
    puts("\nSorted names:\n");
    showarray(vals, NUM);
    return 0;
}

void showarray(const Name ar[], int n)
{
    int index;

    for (index = 0; index < n; index++)
    {
        printf("%s %s\n", ar[index].first, ar[index].last);
    }
}

int mycomp(const void * pn1, const void * pn2)
{
    const Name * a1 = (const Name *) pn1;
    const Name * a2 = (const Name *) pn2;
    int cmp_result;

    cmp_result = strcmp(a1->last, a2->last);
    if (cmp_result != 0)
        return cmp_result;
    else
        return strcmp(a1->first, a2->first);
}