#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 20
#define COL 30
#define BUF 40

int main(void)
{
    int arr[ROW][COL];
    int i, j;
    FILE * fp;
    char file_name[BUF];
    char lines[20][31];

    /* Get the file name and read the contents */
    printf("Input the file name: ");
    fgets(file_name, BUF, stdin);
    *(strchr(file_name, '\n')) = '\0';
    if ((fp = fopen(file_name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open the file %s.\n", file_name);
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            fscanf(fp, "%d", &arr[i][j]);
    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing file.\n");
    /* Convert the digital representation to a character */
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            switch (arr[i][j])
            {
                case 0: lines[i][j] = ' '; break;
                case 1: lines[i][j] = '.'; break;
                case 2: lines[i][j] = '\''; break;
                case 3: lines[i][j] = ':'; break;
                case 4: lines[i][j] = '~'; break;
                case 5: lines[i][j] = '*'; break;
                case 6: lines[i][j] = '='; break;
                case 7: lines[i][j] = ','; break;
                case 8: lines[i][j] = '%'; break;
                case 9: lines[i][j] = '#'; break;
            }
        }
        lines[i][j] = '\0';
    }
    /* Display the character picture and store it into a file*/
    printf("Enter the file name to store the picture: ");
    fgets(file_name, BUF, stdin);
    *(strchr(file_name, '\n')) = '\0';
    if ((fp = fopen(file_name, "w")) == NULL)
    {
        fprintf(stderr, "Error in creating %s.\n", file_name);
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < ROW)
    {
        puts(lines[i]);
        fputs(lines[i], fp);
        fputs("\n", fp);
        i++;
    }
    if (fclose(fp) != 0)
        fprintf(stderr, "Error in closing files.\n");
    
    return 0;
}