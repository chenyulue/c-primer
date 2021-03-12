#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256

int main(int argc, char * argv[])
{
    FILE * fp1, * fp2;
    char line1[BUF], line2[BUF];
    char * pt1, * pt2, * newline;

    if (argc != 4 || (strcmp(argv[1], "-a") != 0 && strcmp(argv[1], "-b") != 0))
    {
        printf("Usage: %s -a|-b filepath filepath\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp1 = fopen(argv[2], "r")) == NULL)
    {
        printf("Error in opening %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[3], "r")) == NULL)
    {
        printf("Error in opening %s.\n", argv[3]);
        fclose(fp1);
        exit(EXIT_FAILURE);
    }
    pt1 = fgets(line1, BUF, fp1);
    pt2 = fgets(line2, BUF, fp2);
    if (strcmp(argv[1], "-a") == 0)
    {
        while (pt1 != NULL || pt2 != NULL)
        {
            if (pt1)
            {   
                printf("1> ");
                fputs(line1, stdout);
            }
            if (pt2)
            {
                printf("2> ");    
                fputs(line2, stdout);
            }
            pt1 = fgets(line1, BUF, fp1);
            pt2 = fgets(line2, BUF, fp2);
        }
    }
    if (strcmp(argv[1], "-b") == 0)
    {
        while (pt1 != NULL || pt2 != NULL)
        {
            if (pt1 && !pt2)
            {   
                printf("1> ");
                fputs(line1, stdout);
            }
            else if (!pt1 && pt2)
            {
                printf("2> ");
                printf(line2, stdout);
            }
            else if (pt1 && pt2)
            {
                printf("1,2> ");
                newline = strchr(line1, '\n');
                *newline = '\0';
                fputs(line1, stdout);
                printf("|");
                fputs(line2, stdout);
            }
            pt1 = fgets(line1, BUF, fp1);
            pt2 = fgets(line2, BUF, fp2);            
        }
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}