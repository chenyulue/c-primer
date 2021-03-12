#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double base;
    int exp;

    if (argc < 3)
    {
        printf("Usage: %s double-number integer\n", argv[0]);
        exit(EXIT_FAILURE);
    } else
    {
        printf("%f\n", pow(atof(argv[1]), atoi(argv[2])));
    }

    return 0;
}