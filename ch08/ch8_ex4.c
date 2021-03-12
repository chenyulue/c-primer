#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int word_count = 0;
    int letter_count = 0;
    _Bool in_word = 0;
    int ch;

    while ((ch = getchar()) != EOF)
    {
        if (!isspace(ch))
        {
            if (!in_word && isalnum(ch))
            {
                in_word = 1;
                letter_count++;
            } else if (isalnum(ch))
            {
                letter_count++;
            }
        } else if (isspace(ch) && in_word)
        {
            in_word = 0;
            word_count++;
        }
    }
    printf("The number of letters is %d.\n", letter_count);
    printf("The number of words is %d.\n", word_count);
    printf("The average number of letters per word is %0.2f.\n", (float)letter_count/word_count);

    return 0;
}