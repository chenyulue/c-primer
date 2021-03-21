#include <stdio.h>
#include <stdlib.h>
#include "ch17_ex2.h"

static void CopyToNode(Item item, Node * pnode);

void InitializeList(List *plist)
{
    plist->head = NULL;
    plist->end = NULL;
}

bool ListIsEmpty(const List * plist)
{
    if (plist->head == NULL)
        return true;
    else
        return false;
}

bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL)
        return true;
    else
        full = false;
    free(pt);

    return full;
}

unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = plist->head;

    while (pnode != plist->end)
    {
        count++;
        pnode = pnode->next;
    }

    return count+1;
}

bool AddItem(Item item, List * plist)
{
    Node * pnew;
    Node * scan = plist->head;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL)
    {
        plist->head = pnew;
        plist->end = pnew;
    } else
    {
        plist->end->next = pnew;
        plist->end = pnew;
    }
    return true;
}

void Traverse(const List * plist, void (*pfun)(Item item))
{
    Node * pnode = plist->head;

    while (pnode != NULL)
    {
        pfun(pnode->item);
        pnode = pnode->next;
    }
}

void EmptyTheList(List * plist)
{
    Node * psave;

    while (plist->head != NULL)
    {
        psave = plist->head->next;
        free(plist->head);
        plist->head = psave;
    }
}

static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}
