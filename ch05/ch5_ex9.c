#include <stdio.h>

void Temperatures(double fahrenheit);

int main(void)
{
    double d_fahrenheit;

    printf("Enter a Fahrenheit temperature: ");
    while(scanf("%lf", &d_fahrenheit) == 1)
    {
        Temperatures(d_fahrenheit);
        printf("Enter next Fahrenheit temperature (\"q\" to quit): ");
    }
    
    return 0;

}

void Temperatures(double fahrenheit)
{
    const double KELVIN = 273.16;
    const double FAHRENHEIT_COEF = 5.0/9.0;
    const double FAHRENHEIT = 32.0;
    
    double celsius, kelvin;

    celsius = FAHRENHEIT_COEF * (fahrenheit - FAHRENHEIT);
    kelvin = celsius + KELVIN;
    
    printf("%0.2f Fahrenheit is %0.2f Celsius, which equals %0.2f Kelvin.\n",
           fahrenheit, celsius, kelvin);
}