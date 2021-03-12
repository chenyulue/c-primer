#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF 256

int main(int argc, char * argv[])
{
    char line[BUF];
    FILE * fp;
    int line_count = 0;

    if (argc != 3)
    {
        printf("Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("<Error in opening %s.>\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    printf("Found contents:\n");
    while (fgets(line, BUF, fp) != NULL)
    {
        line_count++;
        if (strstr(line, argv[1]) == NULL)
            continue;
        printf("%3d ", line_count);
        fputs(line, stdout);
    }
    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing file.\n");

    return 0;
}