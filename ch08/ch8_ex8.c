#include <stdio.h>

char display_menu(void);
float get_number(char str[], char);
void display_result(char, float, float);

int main(void)
{
    float first, second;
    char choice;

    while ((choice = display_menu()) != 'q')
    {
        char str1[] = "first";
        first = get_number(str1, choice);
        char str2[] = "second";
        second = get_number(str2, choice);
        display_result(choice, first, second);
    }
    printf("Bye.\n");

    return 0;
}

char display_menu(void)
{
    char ch;

    printf("Enter the operation of your choice:\n");
    printf("a. add               s. substract\n");
    printf("m. multiply          d. divide\n");
    printf("q. quit\n");
    while ((ch = getchar()) != 'q' && ch != 'a' && ch != 's' &&
           ch != 'm' && ch != 'd')
    {
        printf("Only 'a', 's', 'm', 'd', 'q' are allowed. Choose again: ");
    }
    while (getchar() != '\n')
        continue;

    return ch;
}

float get_number(char str[], char choice)
{
    float num;
    char ch;

    printf("Enter %s number: ", str);
    input: while (scanf("%f", &num) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    if (choice == 'd' && num == 0.0f)
    {
        printf("Enter a number other than 0: ");
        goto input;
    }
    while (getchar() != '\n')
        continue;
    
    return num;
}

void display_result(char choice, float first, float second)
{
    switch (choice)
    {
        case 'a': printf("%.2f + %.2f = %.2f\n", first, second, first + second);
                  break;
        case 's': printf("%.2f - %.2f = %.2f\n", first, second, first - second);
                  break;
        case 'm': printf("%.2f * %.2f = %.2f\n", first, second, first * second);
                  break;
        case 'd': printf("%.2f / %.2f = %.2f\n", first, second, first / second);
    }
}