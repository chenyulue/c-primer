#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    int count[argc-2], i, ch;
    FILE * fp;

    if (argc < 2)
    {
        printf("Usage: %s char [files ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    } else if (argc == 2)
    {
        count[0] = 0;
        while ((ch = getchar()) != EOF)
        {
            if (ch == argv[1][0])
                count[0]++;
        }
        printf("The number of %c in stdin: %d.\n", argv[1][0], count[0]);
    } else
    {
        for (i = 2; i < argc; i++)
        {
            count[i-2] = 0;
            if ((fp = fopen(argv[i], "r")) == NULL)
            {
                printf("<Can't open %s.>\n", argv[i]);
                continue;
            }
            while ((ch = getc(fp)) != EOF)
            {
                if (ch == argv[1][0])
                    count[i-2]++;
            }
            printf("The number of %c in %s: %d.\n", argv[1][0], argv[i], count[i-2]);
        }
    }
}