#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

static void showword(Item item);
static int menu(void);
static void find_most(Item item);

int main(int argc, char * argv[])
{
    FILE * pf;
    char word[WORDSIZE];
    char ch;
    Item item;
    Tree word_tree;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((pf = fopen(argv[1], "r")) == NULL)
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

            char * pchr;
            for ( pchr = word, i = 0; *pchr; pchr++, i++)
                word[i] = tolower(word[i]);

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

    int choice;
    while ((choice = menu()) != 4)
    {
        const Item * lookup;
        Item tosearch;
        switch (choice)
        {
            case 1: 
                Traverse(&word_tree, showword);
                printf("\n");
                break;
            case 2:
                printf("Enter a word: ");
                scanf("%s", word);
                strcpy(tosearch.word, word);
                tosearch.count = 1;
                lookup = LookUp(&tosearch, &word_tree);
                if (lookup != NULL)
                    printf("%s: %d\n", lookup->word, lookup->count);
                else
                    printf("Not found %s\n", word);
                while (getchar() != '\n');
                printf("\n");
                break;
            case 3:
                Traverse(&word_tree, find_most);
                printf("\n");
                break;
            default:
                printf("Only 1 to 4 are allowed.\n\n");
        }
    }
    DeleteAll(&word_tree);
    fclose(pf);

    return 0;
}

static void showword(Item item)
{
    printf("%s: %d\n", item.word, item.count);
}

static int menu(void)
{
    int code;

    printf("Enter your choice:\n");
    printf("1) List all words       2) Find a word\n");
    printf("3) Most frequent word   4) Quit\n");
    printf("?> ");
    while (scanf("%d", &code) != 1)
    {
        while (getchar() != '\n')
            continue;
        printf("?> ");
    }
    while (getchar() != '\n')
        continue;
    
    return code;
}

static void find_most(Item item)
{
    static int count = 0;
    static Item pitem;
    if (item.count > count)
    {
        count = item.count;
        pitem = item;
        printf("The most frequent word is %s, with %d times.\n", item.word, item.count);
    }
}