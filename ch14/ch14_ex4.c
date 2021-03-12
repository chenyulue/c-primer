#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct name_st {
    char first[40];
    char middle[40];
    char last[40];
} Name;

typedef struct id_st {
    char security_num[40];
    Name name;
} ID;

#ifdef EXA
void show_name(const Name * name);
#else
void show_name(Name  name);
#endif
void show_id(ID *idarr, int num);
char * upper_first(const char * str);

int main(void)
{
    ID id[5] = {
        {"302039823", {"Dribble", "Mike", "Flossie"}},
        {"302084723", {"Tom", "", "Smith"}},
        {"403928574", {"Jhon", "Hellen", "McDonald"}},
        {"239403242", {"Rudy", "", "Van"}},
        {"837203842", {"lily", "jhon", "Byden"}}
    };
    show_id(id, 5);

    return 0;
}

#ifdef EXA
void show_id(ID * idarr, int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        show_name(&idarr[i].name);
        printf(" ---- %s\n", idarr[i].security_num);
    }
}

void show_name(const Name * name)
{
    char * first = upper_first(name->first);
    char * last = upper_first(name->last);
    if (name->middle[0] == '\0')
    {
        printf("%s, %s", first, last);
    } else
    {
        printf("%s, %s %c.", first, last, toupper(name->middle[0]));
    }
    free(first);
    free(last);
}
#else
void show_id(ID * idarr, int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        show_name(idarr[i].name);
        printf(" ---- %s\n", idarr[i].security_num);
    }
}

void show_name(Name name)
{
    char * first = upper_first(name.first);
    char * last = upper_first(name.last);
    if (name.middle[0] == '\0')
    {
        printf("%s, %s", first, last);
    } else
    {
        printf("%s, %s %c.", first, last, toupper(name.middle[0]));
    }
    free(first);
    free(last);
}
#endif

char * upper_first(const char * str)
{
    size_t len = strlen(str) + 1;
    char * tmp = malloc(len);
    strcpy(tmp, str);
    tmp[0] = toupper(tmp[0]);
    return tmp;
}
