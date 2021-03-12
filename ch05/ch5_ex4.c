#include <stdio.h>
#define CM_PER_FOOT 30.48
#define INCHES_PER_FOOT 12.0

int main(void)
{
    float height;

    printf("Enter a height in centimeters: ");
    scanf("%f", &height);
    while(height > 0)
    {
        float f_feet = height / CM_PER_FOOT;
        int i_feet = (int)f_feet;
        float f_inches = (f_feet - i_feet) * INCHES_PER_FOOT;
        printf("%0.1f cm = %d feet, %0.1f inches\n",
               height, i_feet, f_inches);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &height);
    }
    printf("bye!");

    return 0;
}