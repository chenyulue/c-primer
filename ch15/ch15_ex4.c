#include <stdio.h>
#include <stdbool.h>

bool is_on_at(int number, int position);

int main(void)
{
    int num, pos;

    while (scanf("%d %d", &num, &pos) == 2)
    {
        printf("Position %d in %d is %s.\n", pos, num, is_on_at(num, pos) ? "on" : "off");
    }

    return 0;
}

bool is_on_at(int number, int position)
{
    return 01 & (number >> (position - 1));
}