/* ex_ch2.c -- programming exercises in chapter 2*/
#include <stdio.h>

void jolly(void);
void deny(void);
void br(void);
void ic(void);
void smile(void);
void one_three(void);
void two(void);

int main(void)
{
    int age = 35;
    int toes = 10;

    // exercise 1
    printf("<Exercise 1>:\n");
    printf("Gustav Mahler\n");
    printf("Gustav\nMahler\n");
    printf("Gustave ");
    printf("Mahler\n");

    // exercise 2
    printf("\n<Exercise 2>:\n");
    printf("My name is Chenyu Lue, living in Suzhou.\n");

    // exercise 3
    printf("\n<Exercise 3>:\n");
    printf("My age is %d years old, which is %d days.\n", age, age*365);

    // exercise 4
    printf("\n<Exercise 4>:\n");
    jolly();
    jolly();
    jolly();
    deny();

    //exercise 5
    printf("\n<Exercise 5>:\n");
    br();
    printf(", ");
    ic();
    printf("\n");
    ic();
    printf(",\n");
    br();
    printf("\n");

    // exercise 6
    printf("\n<Exercise 6>:\n");
    printf("toes = %d\ntwice toes = %d\ntoes squared = %d\n", toes, toes*2, toes*toes);

    // exercise 7
    printf("\n<Exercise 7>:\n");
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    printf("\n");

    // exercise 8
    printf("\n<Exercise 8>:\n");
    printf("starting now:\n");
    one_three();
    printf("done!\n");

    return 0;
}

void jolly(void)
{
    printf("For he's a jolly good fellow!\n");
}

void deny(void)
{
    printf("Which nobody can deny!\n");
}

void br(void)
{
    printf("Brazil, Russia");
}

void ic(void)
{
    printf("India, China");
}

void smile(void)
{
    printf("Smile!");
}

void one_three(void)
{
    printf("one\n");
    two();
    printf("three\n");
}

void two(void)
{
    printf("two\n");
}