#include <stdio.h>
#include "stack.h"

int main(void)
{
    char input;
    Stack st;

    InitializeStack(&st);
    while ((input = getchar()) != '\n')
        Push(input, &st);
    while (!EmptyStack(&st))
    {
        Pop(&input, &st);
        putchar(input);
    }
    putchar('\n');

    return 0;
}