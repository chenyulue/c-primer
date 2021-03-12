#include <stdio.h>
#include <string.h>
#include <float.h>

#define LITERS_PER_GALLON 3.785
#define KM_PER_MILE 1.609

int main(void)
{
    float miles;
    float gallons;

    float f = 1.0f/3.0f;
    double d = 1.0/3.0;

    float file_size;
    float speed;
    float times;

    float inches;
    float num;
    // exercise 1
    char first_name[40];
    char last_name[40];
    printf("Enter your first name and last name: ");
    scanf("%s %s", first_name, last_name);
    printf("Your name is %s, %s\n", last_name, first_name);

    // exercise 2
    printf("Enter your first name: ");
    scanf("%s", first_name);
    printf("a: \"%s\"\n", first_name);
    printf("b: \"%20s\"\n", first_name);
    printf("c: \"%-20s\"\n", first_name);
    printf("d: %*s\n", strlen(first_name)+3, first_name);

    // exercise 3
    printf("Enter a floating-point number: ");
    scanf("%f", &num);
    printf("a: The input is %0.1f or %0.1e\n", num, num);
    printf("b: The input is %+0.3f or %0.3E\n", num, num);

    // exercise 4
    printf("Enter your height in inches: ");
    scanf("%f", &inches);
    printf("Enter your name: ");
    scanf("%s", first_name);
    printf("%s, you are %0.3f feet tall.\n", first_name, inches/12.);

    // exercise 5
    printf("Enter the download speed (Mbs/sec) and the size of file (MB) sequentially: ");
    scanf("%f %f", &speed, &file_size);
    printf("At %0.2f megabits per second, a file of %0.2f megabytes\n"
           "downloads in %0.2f seconds.\n", speed, file_size, file_size*8/speed);

    // exercise 6
    printf("Enter your first name and last name: ");
    scanf("%s %s", first_name, last_name);
    printf("%s\t%s\n", first_name, last_name);
    printf("%*zd\t%*zd\n", strlen(first_name), strlen(first_name), 
           strlen(last_name), strlen(last_name));
    printf("%-*zd\t%-*zd\n", strlen(first_name), strlen(first_name), 
           strlen(last_name), strlen(last_name));    
    
    // exercise 7
    printf("FLT_DIG: %d\n", FLT_DIG);
    printf("DBL_DIG: %d\n", DBL_DIG);
    printf("f: %0.4f\t%0.12f\t%0.16f\n", f, f, f);
    printf("d: %0.4f\t%0.12f\t%0.16f\n", d, d, d);

    // exercise 8
    printf("Enter the number of miles and number of gallons: ");
    scanf("%f %f", &miles, &gallons);
    printf("With %.3f miles travled and %.f gallons of gasoline consumed,\n", miles, gallons);
    printf("the miles-per-gallon is %.3f\n", miles/gallons);
    printf("and liters-per-100-km is %.3f\n", 
           100 * gallons * LITERS_PER_GALLON / (miles * KM_PER_MILE));

    return 0;
}