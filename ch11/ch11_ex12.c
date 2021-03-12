#include <stdio.h>
#include <ctype.h>

void count(char line[], unsigned * wd, unsigned * upper, unsigned * lower, unsigned * punct, unsigned * digits);

int main(void)
{
    char line[40];
    unsigned num_wd, num_upper, num_lower, num_punct, num_digits;

    num_wd = num_upper = num_lower = num_punct = num_digits = 0;
    printf("Enter lines (EOF to quit):\n");
    while (fgets(line, 40, stdin))
    {
        count(line, &num_wd, &num_upper, &num_lower, &num_punct, &num_digits);
    }
    printf("Number of words: %u\n", num_wd);
    printf("Number of uppercase letters: %u\n", num_upper);
    printf("Number of lowercase letters: %u\n", num_lower);
    printf("Number of punctuation characters: %u\n", num_punct);
    printf("Number of digits: %u\n", num_digits);

    return 0;
}

void count(char line[], unsigned * wd, unsigned * upper, unsigned * lower, unsigned * punct, unsigned * digits)
{
    _Bool inword = 0;

    while (*line != '\0')
    {
        if (!inword && !isspace(*line))
        {
            inword = 1;
            if (isupper(*line))
                (*upper)++;
            else if (islower(*line))
                (*lower)++;
            else if (ispunct(*line))
                (*punct)++;
            else if (isdigit(*line))
                (*digits)++;
        } else if (inword && isspace(*line))
        {
            (*wd)++;
            inword = 0;
        } else if (inword && !isspace(*line))
        {
            if (isupper(*line))
                (*upper)++;
            else if (islower(*line))
                (*lower)++;
            else if (ispunct(*line))
                (*punct)++;
            else if (isdigit(*line))
                (*digits)++;
        }
        line++;
    }
}