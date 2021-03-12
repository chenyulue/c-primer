#include <stdio.h>

int main(void)
{
    int count;
    char pre, current;

    count = 0;
    printf("Enter a string, ended with #: ");
    pre = getchar();
    while (pre != '#' && (current = getchar()) != '#')
    {
        if (current == 'i' && pre == 'e')
        {
            count++;
        } else
        {
            pre = current;
        }
    }
    printf("The sequence \"ei\" occurs %d times.\n", count);

    return 0;
    
}