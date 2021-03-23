#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

#define WORDSIZE 255
#define SLEN 20

#ifndef CH17_EX8
typedef struct item {
    char word[WORDSIZE];
    int count;
} Item;

#define MAXITEMS 10
#else
typedef struct kind {
    char petkind[SLEN];
    struct kind * next;
} PetKind;

typedef struct item {
    char petname[SLEN];
    PetKind * petkinds;
} Item;

#endif

typedef struct trnode {
    Item item;
    struct trnode * left;
    struct trnode * right;
} Trnode;

typedef struct tree {
    Trnode * root;
    int size;
} Tree;

/* function prototypes */
void InitializeTree (Tree * ptree);

bool TreeIsEmpty(const Tree * ptree);

bool TreeIsFull(const Tree * ptree);

int TreeItemCount(const Tree * ptree);

bool AddItem(const Item * pi, Tree * ptree);

bool InTree(const Item * pi, const Tree * ptree);

bool DeleteItem(const Item * pi, Tree * ptree);

void Traverse (const Tree * ptree, void (* pfun)(Item item));

void DeleteAll (Tree * ptree);

const Item * LookUp(const Item * pi, const Tree * ptree);

#endif