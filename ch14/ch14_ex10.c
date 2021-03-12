#include <stdio.h>
#include <math.h>

typedef double (*func)(double);
double get_num(void);
void menu(void);

int main(void)
{
    func farr[4] = {sin, sqrt, exp, acos};
    char code;
    int index;
    double num;

    menu();
    while ((code = getchar()) != EOF && code != 'e')
    {
        while (getchar() != '\n')
            continue;
        index = code - 'a';
        if (index < 0 || index > 3)
        {
            printf("Only a to e are allowed. Input again: ");
            continue;
        }
        num = get_num();
        printf("The result is %.2f.\n\n", farr[index](num));
        menu();
    }
    printf("Bye!\n");

    return 0;
}

double get_num(void)
{
    double num;

    printf("Enter a number: ");
    while (scanf("%lf", &num) != 1)
    {
        printf("Only a number allowed: ");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;
    
    return num;
}

void menu(void)
{
    printf("To choose the function, enter the label letter:\n");
    printf("  a) sin                 b) sqrt\n");
    printf("  c) exp                 d) acos\n");
    printf("  e) quit\n");
    printf("?> ");
}