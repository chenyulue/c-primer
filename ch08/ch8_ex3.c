#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int count_lower = 0;
    int count_upper = 0;
    int count_other = 0;
    int ch;

    printf("Enter a string of input:\n");
    while((ch = getchar()) != EOF)
    {
        if (islower(ch))
            count_lower++;
        else if (isupper(ch))
            count_upper++;
        else
            count_other++;
    }
    printf("The number of uppercase letters: %d\n", count_upper);
    printf("The number of lower letters: %d\n", count_lower);
    printf("The number of other characters: %d\n", count_other);

    return 0;
}