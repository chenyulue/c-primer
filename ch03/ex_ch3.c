#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    int code;
    float num;

    const double SECONDS_IN_A_YEAR = 3.156e7;
    double age;

    const double MASS = 3.0e-23;
    const double QUART = 950.;
    double quarts;

    const double CENTI_PER_INCH = 2.54;
    double inches;

    float cups;

    // exercise 1
    printf("<Exercise 1>:\n");
    printf("The maximum integer in my system are %d, "
           "the overflow of which by adding 1 is %d\n",
           INT_MAX, INT_MAX+1);
    printf("The maximum floating-point in my system are %e, "
           "the overflow of which by multiplying 10 is %e\n",
           FLT_MAX, FLT_MAX * 10);
    printf("The minimum floating-point in my system are %e, "
           "the underflow of which by dividing it by 10000000 is %e\n",
           FLT_MIN, FLT_MIN / 10000000);

    // exercise 2
    printf("\n<Exercise 2>:\n");
    printf("Enter an ASCII code value: ");
    scanf("%d", &code);
    printf("The ASCII code value of %d represents the character %c\n", code, code);

    // exercise 3
    printf("\n<Exercise 3>:\n");
    printf("\aStartled by the sudden sound, Sally shouted,\n");
    printf("\"By the Greate Pumpkin, what was that!\"\n");

    // exercise 4
    printf("\n<Exercise 4>:\n");
    printf("Enter a floating-point value: ");
    scanf("%f", &num);
    printf("fixed-point notation: %f\n", num);
    printf("exponential notation: %e\n", num);
    printf("p notation: %a\n", num);

    // exercise 5
    printf("\n<Exercise 5>:\n");
    printf("Enter your age: ");
    scanf("%lf", &age);
    printf("Your age in seconds are: %f\n", age * SECONDS_IN_A_YEAR);

    // exercise 6
    printf("\n<Exercise 6>:\n");
    printf("Enter the amount of water in quarts: ");
    scanf("%lf", &quarts);
    printf("The number of water molecules is: %e\n", quarts * QUART / MASS);

    // exercise 7
    printf("\n<Exercise 7>:\n");
    printf("Enter your height in inches: ");
    scanf("%lf", &inches);
    printf("Your height is %.2f in centimeters.\n", inches * CENTI_PER_INCH);

    // exercise 8
    printf("\n<Exercise 8>:\n");
    printf("Enter a volume in cups: ");
    scanf("%f", &cups);
    printf("%.f cups equals %.2f pints, %.f ounces, %.f tablespoons"
           " or %.f teaspoons.\n", cups, cups/2, cups*8, cups*8*2, cups*8*2*3);



    return 0;
}