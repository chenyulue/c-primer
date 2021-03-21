#include "stack.h"

static void CopyToItem(Item item, Item * pitem);
static void CopyToStack(Item item, Stack * ps);

void InitializeStack(Stack * ps)
{
    ps->top = 0;
}

bool FullStack(const Stack * ps)
{
    return ps->top == MAXSTACK;
}

bool EmptyStack(const Stack * ps)
{
    return ps->top == 0;
}

bool Push(Item item, Stack * ps)
{
    CopyToStack(item, ps);
    ps->top++;
}

bool Pop(Item * pitem, Stack * ps)
{
    ps->top--;
    CopyToItem(ps->items[ps->top], pitem);
}

static void CopyToItem(Item item, Item * pitem)
{
    *pitem = item;
}
static void CopyToStack(Item item, Stack * ps)
{
    ps->items[ps->top] = item;
}