#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUF 256

int main(void)
{
    char source[BUF], target[BUF];
    int ch;
    char * newline;
    FILE * fps, * fpt;

    printf("Enter the source file: ");
    fgets(source, BUF, stdin);
    newline = strchr(source, '\n');
    *newline = '\0';
    printf("Enter the target file: ");
    fgets(target, BUF, stdin);
    newline = strchr(target, '\n');
    *newline = '\0';
    if ((fps = fopen(source, "r")) == NULL)
    {
        printf("Error in opening %s.\n", source);
        exit(EXIT_FAILURE);
    }
    if ((fpt = fopen(target, "w")) == NULL)
    {
        printf("Error in creating %s.\n", target);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fps)) != EOF)
    {
        putc(toupper(ch), fpt);
    }
    printf("Copy is done.\n");
    fclose(fps);
    fclose(fpt);

    return 0;
}