#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
    FILE * fp;
    char words[MAX];
    int count, status;

    count = 1;
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stderr, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file; press the Enter");
    puts("key at the beginning of a line to termination.");
    rewind(fp);
    while (fgets(words, MAX, fp) != NULL)
        count++;
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '\0'))
    {
        fprintf(fp, "%-3d ", count++);
        fprintf(fp, "%s\n", words);
    }
    puts("File contents:");
    rewind(fp);
    while (fscanf(fp, "%d %s", &count, words) == 2)
        printf("%-3d %s\n", count, words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}