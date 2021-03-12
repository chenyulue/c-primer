#include <stdio.h>
#include <string.h>

char * mystrncpy(char * target, const char * source, int max);

int main(void)
{
    char s1[40], s2[20];

    while (scanf("%19s", s2) == 1)
    {
        printf("Inputted string is \"%s\".\n", s2);
        printf("Copied string is \"%s\".\n", mystrncpy(s1, s2, 10));
    }

    return 0;

}

char * mystrncpy(char * target, const char * source, int max)
{
    int i;

    for (i = 0; i < max; i++)
    {
        if (i >= strlen(source))
            target[i] = '\0';
        else
            target[i] = source[i];
    }
    
    return target;
}