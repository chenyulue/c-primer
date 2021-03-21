#include <stdio.h>
#include <stdlib.h>
#define CH17_EX3_H_
#include "ch17_ex2.h"

static void CopyToNode(Item item, Node * pnode);

void InitializeList(List *plist)
{
    plist->items = 0;
}

bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

bool ListIsFull(const List * plist)
{
    if (plist->items == MAXSIZE)
        return true;
    else
        return false;
}

unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

bool AddItem(Item item, List * plist)
{
     if (ListIsFull(plist))
        return false;
    (plist->entries)[plist->items] = item;
    plist->items++;
    return true;
}

void Traverse(const List * plist, void (*pfun)(Item item))
{
    int i;

    for (i = 0; i < plist->items; i++)
        pfun((plist->entries)[i]);
}

void EmptyTheList(List * plist)
{
    plist->items = 0;
}

static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}
