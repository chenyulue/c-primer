#include <stdio.h>
#include <string.h>
#define Q "His Hamlet was funny without being vulgar."
#define BOOK "War and Peace"

int main(void)
{
    float cost = 12.99;
    float percent = 80.0;

    printf("He sold the painting for $%2.2f.\n", 2.345e2);
    printf("%c%c%c\n", 'H', 105, '\41');
    printf("\"%s\"\nhas %d characters.\n", Q, strlen(Q));
    printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);

    printf("This copy of \"%s\" sells for $%.2f.\n"
           "That is %.f%% of list.", BOOK, cost, percent);
}