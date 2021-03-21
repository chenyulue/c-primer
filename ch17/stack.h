/* Type Name: Stack.
Type Properties: Can hold an ordered sequence of items.
Type Operations: Initialize statck to empty.
                 Determine whether stack is empty.
                 Determine whether stack is full.
                 Add item to top of stack (pushing an item).
                 Remove and recover item from top of stack (popping an item).
*/
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

#define MAXSTACK 100

typedef char Item;

typedef struct stack {
    Item items[MAXSTACK];
    int top;
} Stack;

void InitializeStack(Stack * ps);

bool FullStack(const Stack * ps);

bool EmptyStack(const Stack * ps);

bool Push(Item item, Stack * ps);

bool Pop(Item * pitem, Stack * ps);

#endif