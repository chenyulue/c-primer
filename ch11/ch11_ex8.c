#include <stdio.h>

char * string_in(const char * s1, const char * s2);

int main(void)
{
    char str1[40], str2[40];
    char * str;

    while (scanf("%s %s", str1, str2) == 2)
    {
        str = string_in(str1, str2);
        if (str)
            printf("\"%s\" is in \"%s\" at %s.\n", str2, str1, str);
        else
            printf("\"%s\" is not in \"%s\".\n", str2, str1);
    }

    return 0;
}

char * string_in(const char * s1, const char * s2)
{
    const char * tmp1, * tmp2;
    while (*s1 != '\0')
    {
        if (*s1 == *s2)
        {
            tmp1 = s1 + 1;
            tmp2 = s2 + 1;
            while (*tmp2 != '\0')
            {
                if (*tmp2 == *tmp1)
                {
                    tmp2++;
                    tmp1++;
                    continue;
                }
                else
                    break;
            }
            if (*tmp2 == '\0')
                return (char *) s1;
        }
        s1++;
    }

    return NULL;
}