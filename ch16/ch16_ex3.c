#include <stdio.h>
#include <math.h>
#include "ch16_ex1.h"

int main(void)
{
    Polar polar;
    Rect rect;

    printf("Input the magnitude and the angle (in degrees): ");
    while (scanf("%lf %lf", &polar.magnitude, &polar.angle) == 2)
    {
        rect = polarToRect(&polar);
        printf("The corresponding rectangular coordinates are (%.2f, %.2f)\n", rect.x, rect.y);
        printf("Input the magnitude and the angle (in degrees): ");
    }

    return 0;
}

Rect polarToRect(const Polar * polar)
{
    Rect rect;

    rect.x = polar->magnitude * cos(polar->angle * PI / 180);
    rect.y = polar->magnitude * sin(polar->angle * PI / 180);

    return rect;
}