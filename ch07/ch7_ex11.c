#include <stdio.h>
#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09
#define DISCOUNT 0.05
#define FIRST_POUNDS 5.0
#define FIRST_SHIPPING 6.5
#define SECOND_POUNDS 20.0
#define SECOND_SHIPPING 14.0
#define THIRD_EXTRA_RATE 0.5

double get_pounds(void);
int main(void)
{
    double pounds_a, pounds_b, pounds_c, pounds_total, pounds, discount, total, shipping;
    char ch;

    pounds_a = pounds_b = pounds_c = pounds_total = discount = total = 0.0;
    shipping = 0.0;
    printf("***************************************************\n");
    printf("Enter the grocery and the pounds you want to buy:\n");
    printf("a) Artichokes ($2.05/pound)\n"
           "b) Beets ($1.15/poind)\n"
           "c) Carrots ($1.09/poind)\n"
           "q) Quit\n");
    printf("***************************************************\n");
    while ((ch = getchar()) != 'q')
    {
        while (getchar() != '\n')
            continue;
        switch (ch)
        {
            case 'a': pounds_a += get_pounds();
                      total += pounds_a*ARTICHOKE;
                      break;
            case 'b': pounds_b += get_pounds();
                      total += pounds_b*BEET;
                      break;
            case 'c': pounds_c += get_pounds();
                      total += pounds_c*CARROT;
                      break;
            default: printf("Only a, b, c or q are allowed inputs. Enter again: ");
        }
    }
    pounds_total += pounds_a + pounds_b + pounds_c;
    if (total >= 100)
        discount = pounds_total * DISCOUNT;
    if (pounds_total <= FIRST_POUNDS)
    {
        shipping += FIRST_SHIPPING;
    } else if (pounds_total < SECOND_POUNDS)
    {
        shipping += SECOND_SHIPPING;
    } else
    {
        shipping += SECOND_SHIPPING + THIRD_EXTRA_RATE * pounds_total;
    }
    printf("The cost per pound: %.2f\n", (total - discount) / pounds_total);
    printf("The pounds ordered: %.2f\n", pounds_total);
    printf("The costs for artichokes: %.2f\n", pounds_a*ARTICHOKE);
    printf("          for beets: %.2f\n", pounds_b*BEET);
    printf("          for carrots: %.2f\n", pounds_c*CARROT);
    printf("The total cost: %.2f\n", total-discount);
    printf("The discount: %.2f\n", discount);
    printf("The shipping charge: %.2f\n", shipping);
    printf("The grand total of all the charges: %.2f\n", total-discount+shipping);
}

double get_pounds(void)
{
    double pounds;

    printf("Enter pounds: ");
    while (scanf("%lf", &pounds) != 1)
    {
        printf("Not a number. Enter again: ");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;
    return pounds;
}