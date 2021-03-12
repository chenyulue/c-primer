#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc_mean(FILE * fpt);
int main(int argc, char *argv[])
{
    FILE * fpt;
    double avg;
    if (argc < 2)
    {
        avg = calc_mean(stdin);
    } else if (argc == 2)
    {
        if ((fpt = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        avg = calc_mean(fpt);
        fclose(fpt);
    } else
    {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (isnan(avg))
        printf("No valid data.\n");
    else
        printf("The arithmetic mean of the input numbers is %.4f.\n", avg);

    return 0;
}

double calc_mean(FILE * fpt)
{
    double num;
    double total = 0.0;
    int count = 0;

    while(fscanf(fpt, "%lf", &num) == 1)
    {
        total += num;
        count++;
    }

    return total / count;

}