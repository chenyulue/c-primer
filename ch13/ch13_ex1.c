#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256

int main(void)
{
    int ch;
    FILE * fp;
    unsigned long count = 0;
    char path[BUF];
    char * end;

    printf("Enter a file path: ");
    fgets(path, BUF, stdin);
    end = strchr(path, '\n');
    *end = '\0';
    if ((fp = fopen(path, "r")) == NULL)
    {
        printf("Can't open %s.\n", path);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %lu characters.\n", path, count);

    return 0;
}