#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256
int main(void)
{
    char file_name[BUF], str[BUF];
    char * newline;
    FILE * fp;
    long pos;

    printf("Input a file name: ");
    fgets(file_name, BUF, stdin);
    if ((newline = strchr(file_name, '\n')) != NULL)
        *newline = '\0';
    else
        file_name[BUF] = '\0';
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        printf("<Error in opening %s.>\n", file_name);
        exit(EXIT_FAILURE);
    }
    printf("Enter the position offset from the start: ");
    while (scanf("%ld", &pos) == 1)
    {
        if (fseek(fp, pos, SEEK_SET) != 0)
        {
            printf("Error in setting the offset.\n");
            break;
        }
        if (fgets(str, BUF, fp) != NULL)
            fputs(str, stdout);
        else
            printf("Error in reading the content.\n");
        printf("Choose another position offset: ");
    }
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}