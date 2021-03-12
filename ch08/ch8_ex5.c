#include <stdio.h>

int main(void)
{
    int ch;
    int lower = 0;
    int upper = 100;
    int guess = (lower + upper) / 2;

    printf("Pick an integer form 0 to 100. I will try to guess ");
    printf("it.\n Respond with a \"y\" if my guess is right, with");
    printf("\nan \"l\" if it is low and with a \"g\" if it is high.\n");
    printf("Uh... is your number %d?\n", guess);
    while ((ch = getchar ()) != 'y')
    {
        while (getchar() != '\n')
            continue;
        switch (ch)
        {
            case 'l': lower = guess;
                      printf("Uh...is your number %d?\n", (guess = (lower + upper) / 2));
                      break;
            case 'h': upper = guess;
                      printf("Uh...is your number %d?\n", (guess = (lower + upper) / 2));
                      break;
            default:  printf("Invalid response! Respond again: ");
        }
    }
    printf("Yeah! I believe I can do it!\n");

    return 0;
}