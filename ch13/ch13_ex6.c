#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(void)
{
    FILE * in, * out;
    int ch, count = 0;
    char path[LEN], name[LEN];
    char * newline;
    
    printf("Enter the source file: ");
    fgets(path, LEN, stdin);
    newline = strchr(path, '\n');
    if (newline)
        *newline = '\0';
    if ((in = fopen(path, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\".\n", path);
        exit(EXIT_FAILURE);
    }
    strncpy(name, path, LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files.\n");
    
    return 0;
}