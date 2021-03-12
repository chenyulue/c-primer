#include <stdio.h>
#include <string.h>

int main(void)
{
    int idx;
    char word[40];

    printf("Enter a word: ");
    scanf("%s", word);
    for (idx = strlen(word)-1; idx >= 0; idx--)
        printf("%c", word[idx]);
    printf("\n");

    return 0;
}