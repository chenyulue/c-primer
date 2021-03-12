#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    FILE * fpt;
    char line[256];

    if (argc != 3)
    {
        printf("Usage: %s chr filename\n", argv[0]);
        exit(EXIT_FAILURE);
    } else
    {
        if ((fpt = fopen(argv[2], "r")) == NULL)
        {
            printf("Can't open %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
        while (fgets(line, 256, fpt) != NULL)
        {
            if (strchr(line, argv[1][0]) != NULL)
                fputs(line, stdout);
        }
        fclose(fpt);
    }

    return 0;
}