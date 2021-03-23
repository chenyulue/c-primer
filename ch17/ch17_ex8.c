#define CH17_EX8
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "tree.h"

#define eatline while (getchar() != '\n')

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);

int main(void)
{
    Tree pets;
    char choice;
    
    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 'a': 
                addpet(&pets);
                break;
            case 'l':
                showpets(&pets);
                break;
            case 'f':
                findpet(&pets);
                break;
            case 'n':
                printf("%d pets in club\n", TreeItemCount(&pets));
                break;
            case 'd':
                droppet(&pets);
                break;
            default: puts("Switching error");
        }
        printf("\n");
    }
    DeleteAll(&pets);
    puts("Bye!");

    return 0;
}

char menu(void)
{
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the leter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    while ((ch = getchar()) != EOF)
    {
        eatline;
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q: ");
        else
            break;
    }
    if (ch == EOF)
        ch = 'q';
    
    return ch;
}

void addpet(Tree * pt)
{
    Item temp;
    PetKind * pets_kind;

    if (TreeIsFull(pt))
        puts("No room in the club!");
    else
    {
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        pets_kind = (PetKind *) malloc(sizeof (PetKind));
        if (pets_kind == NULL)
        {
            fputs("Error in allocating memory.", stderr);
            exit(1);
        }
        puts("Please enter pet kind:");
        s_gets(pets_kind->petkind, SLEN);
        pets_kind->next = NULL;
        uppercase(temp.petname);
        uppercase(pets_kind->petkind);
        temp.petkinds = pets_kind;
        AddItem(&temp, pt);
    }
}

void showpets(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt, printitem);
}

void printitem(Item item)
{
    PetKind * pk = item.petkinds->next;

    printf("Pet: %-19s\tKind: %-19s\n", item.petname, item.petkinds->petkind);
    while (pk != NULL)
    {
        printf("     %-19s\tKind: %-19s\n", " ", pk->petkind);
        pk = pk->next;
    }
}

void findpet(const Tree * pt)
{
    Item temp;
    const Item * find;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;
    }
    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, SLEN);
    temp.petkinds = NULL;
    uppercase(temp.petname);
    find = LookUp(&temp, pt);
    printf("%s includes ", temp.petname);
    if (find == NULL)
        printf("no pets.\n");
    else
    {
        PetKind * pk = find->petkinds;
        while (pk != NULL)
        {   
            printf("%s%s ", pk->petkind, (pk->next != NULL && pk->next->next == NULL) ? " and" : (pk->next == NULL ? ".\n" : ","));
            pk = pk->next;
        }
    }
}

void droppet(Tree * pt)
{
    Item temp;
    char pet_kind[SLEN];
    Item * find;

    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;
    }
    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    temp.petkinds = NULL;
    puts("Please enter pet kind:");
    s_gets(pet_kind, SLEN);
    uppercase(temp.petname);
    uppercase(pet_kind);
    find = (Item *) LookUp(&temp, pt);
    if (find == NULL)
    {
        printf("No pets named %s are found.\n", temp.petname);
        return;
    }
    PetKind * pk = find->petkinds;
    PetKind * pre;
    char temp_kind[SLEN];
    while (pk != NULL)
    {
        if (strcmp(pk->petkind, pet_kind) == 0)
        {
            if (pk == find->petkinds)
            {
                find->petkinds = pk->next;
            } else
            {
                pre->next = pk->next;
            }
            strcpy(temp_kind, pk->petkind);
            free(pk);
            printf("%s of the %s is deleteed from the clude.\n", find->petname, temp_kind);
            if (find->petkinds == NULL)
                DeleteItem(find, pt);
            else
                pt->size--;
            return;
        }
        pre = pk;
        pk = pk->next;
    }
    printf("Pets name %s is found, but no %s is found.\n", find->petname, pet_kind);
}

void uppercase(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            eatline;
    }

    return ret_val;
}