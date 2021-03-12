#include <stdlib.h>
#include <stdio.h>

#define BUF 256

int main(int argc, char * argv[])
{
    char source[BUF], target[BUF];
    FILE * fps, *fpt;
    int ch;

    if (argc != 3)
    {
        printf("Usage: %s source_file target_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fps = fopen(argv[1], "rb")) == NULL)
    {
        printf("Error: can't open %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fpt = fopen(argv[2], "wb")) == NULL)
    {
        printf("Error: can't create %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fps)) != EOF)
    {
        putc(ch, fpt);
    }
    printf("Copy is down!\n");
    fclose(fps);
    fclose(fpt);

    return 0;
}