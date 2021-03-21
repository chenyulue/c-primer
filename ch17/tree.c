#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define CH17_EX8
#include "tree.h"
//#define DEBUG

typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

static Trnode * MakeNode(const Item * pi);
static int Compare(const Item * item1, const Item * item2);
static void AddNode(Trnode * new_node, Trnode * root);
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Trnode ** ptr);
static void DeleteAllNodes(Trnode * ptr);
static void InOrder(const Trnode * root, void (*pfun)(Item item));

void InitializeTree (Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    return ptree->root == NULL;
}

bool TreeIsFull(const Tree * ptree)
{
    Trnode * ptr;
    bool full;

    ptr = (Trnode *) malloc(sizeof(Trnode));
    if (ptr == NULL)
        full = true;
    else
        full = false;
    free(ptr);
    return full;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

#ifndef CH17_EX8
bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode * new_node;
    Trnode * find;

    if (TreeIsFull(ptree))
    {
        fputs("Tree is full.", stderr);
        return false;
    }
    if ((find = SeekItem(pi, ptree).child) != NULL)
    {
        find->item.count++;
        return true;
    }
    new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fputs("Couldn't create a node.", stderr);
        return false;
    }
    ptree->size++;
    if (ptree->root == NULL)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);
    return true;
}
#else
bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode * new_node;
    Trnode * find;

    if (TreeIsFull(ptree))
    {
        fputs("Tree is full.", stderr);
        return false;
    }
    if ((find = SeekItem(pi, ptree).child) != NULL)
    {
        PetKind * pk = find->item.petkinds;
        while (pk->next != NULL)
        {
            if (strcmp(pk->petkind, pi->petkinds) == 0)
                return false;
        }
        pk->next = pi->petkinds;
        ptree->size++;
        return true;
    }
    new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fputs("Couldn't create a node.", stderr);
        return false;
    }
    ptree->size++;
    if (ptree->root == NULL)
        ptree->root = new_node;
    else
        AddNode(new_node, ptree->root);
    return true;
}
#endif

bool InTree(const Item * pi, const Tree * ptree)
{
    return SeekItem(pi, ptree).child != NULL;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
    Pair look;

    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;
    if (look.parent == NULL)
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;

    return true;
}

void Traverse (const Tree * ptree, void (* pfun)(Item item))
{
    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll (Tree * ptree)
{
    if (ptree->root != NULL)
    {
        DeleteAllNodes(ptree->root);
    }
    ptree->size = 0;
    ptree->root = NULL;
}

const Item * LookUp(const Item * pi, const Tree * ptree)
{
    Pair look = SeekItem(pi, ptree);

    if (look.child != NULL)
        return &(look.child->item);
    return NULL;
}

/* Local function */
static void InOrder(const Trnode * root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        pfun(root->item);
        InOrder(root->right, pfun);
    }
}

static void AddNode(Trnode * new_node, Trnode * root)
{
    if (Compare(&new_node->item, &root->item) < 0)
    {
        if (root->left == NULL)
            root->left = new_node;
        else
            AddNode(new_node, root->left);  
    } else if (Compare(&new_node->item, &root->item) > 0)
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    } else
    {
        fputs("location error in AddNode()", stderr);
        exit(1);
    }
}

static Trnode * MakeNode(const Item * pi)
{
    Trnode * new_node;

    new_node = (Trnode *) malloc(sizeof (Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;
    while (look.child != NULL)
    {
        if (Compare(pi, &(look.child->item)) < 0)
        {
            look.parent = look.child;
            look.child = look.child->left;
        } else if (Compare(pi, &(look.child->item)) > 0)
        {
            look.parent = look.child;
            look.child = look.child->right;
        } else
            break;
    }
    return look;
}

#ifndef CH17_EX8
static int Compare(const Item * item1, const Item * item2)
{
    return strcmp(item1->word, item2->word);
}

static void DeleteAllNodes(Trnode * ptr)
{
    if (ptr != NULL)
    {
        Trnode * right = ptr->right;
        DeleteAllNodes(ptr->left);
        free(ptr);
        DeleteAllNodes(ptr->right);
    }
}

static void DeleteNode(Trnode ** ptr)
{
    Trnode * temp;

    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    } else
    {
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp  = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    } 
}
#else
static int Compare(const Item * item1, const Item * item2)
{
    return strcmp(item1->petname, item2->petname);
}

static void ClearList(PetKind * root)
{
    PetKind * temp;

    while (root != NULL)
    {
        temp = root;
        root = root->next;
        free(temp);
    }
}
static void DeleteAllNodes(Trnode * root)
{
    Trnode * pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        ClearList(root->item.petkinds);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void DeleteNode(Trnode ** ptr)
{
    Trnode * temp;

    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        ClearList(temp->item.petkinds);
        free(temp);
    } else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        ClearList(temp->item.petkinds);
        free(temp);
    } else
    {
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp  = *ptr;
        *ptr = (*ptr)->left;
        ClearList(temp->item.petkinds);
        free(temp);
    } 
}

#endif

#ifdef DEBUG
#include <ctype.h>
static void showword(Item item);

int main(int argc, char * argv[])
{
    FILE * pf;
    char word[WORDSIZE];
    char ch;
    Item item;
    Tree word_tree;
/*
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }*/
    if ((pf = fopen("C:\\Users\\xj\\cpp\\c-primer\\ch17\\test.txt", "r")) == NULL)
    {
        fputs("Error in opening the file.", stderr);
        exit(EXIT_FAILURE);
    }
    InitializeTree(&word_tree);
    while ((ch = fgetc(pf)) != EOF)
    {
        if (isalnum(ch) || ch == '\'')
        {
            int i;

            for (i = 0; isalnum(ch) || ch == '\''; i++)
            {
                word[i] = ch;
                ch = fgetc(pf);
            }
            if (word[i-1] == '\'')
                word[i-1] = '\0';
            else
                word[i] = '\0';
            if (word[0] == '\'')
            {
                item.count = 1;
                strcpy(item.word, word + 1);
            } else
            {
                item.count = 1;
                strcpy(item.word, word);
            }
            AddItem(&item, &word_tree);
        }
    }
    Traverse(&word_tree, showword);
    DeleteAll(&word_tree);

    return 0;
}

static void showword(Item item)
{
    printf("%s: %d\n", item.word, item.count);
}
#endif