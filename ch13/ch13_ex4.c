#include <stdio.h>
#include <stdlib.h>

#define BUF 256

int main(int argc, char * argv[])
{
    int i, ch;
    FILE * fp;

    if (argc < 2)
    {
        printf("Usage: %s [filename ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (i = 1; i < argc; i++)
    {
        printf("\n%s:\n", argv[i]);
        if ((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("\nError in opening %s.\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((ch = getc(fp)) != EOF)
            putc(ch, stdout);
        fclose(fp);
    }

    return 0;
}