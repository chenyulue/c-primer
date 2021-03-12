#include "ch14_ex5_ab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CSIZE 4

void get_scores(Student * stud, int num);
void calc_scores(Student * stud, int num);
void show_info(const Student * stud, int num);
void show_average(const Student * stud, int num);
char * get_name(const Student * stud);

int main(void)
{
    Student students[CSIZE] = {
        {{"John", "Smith"}},
        {{"Tom", "Byden"}},
        {{"Rudy", "Van"}},
        {{"Kate", "Helen"}}
    };

    get_scores(students, CSIZE);
    calc_scores(students, CSIZE);
    printf("The students information:\n");
    show_info(students, CSIZE);
    printf("\nThe class average information:\n");
    show_average(students, CSIZE);

    return 0;
}

void get_scores(Student * stud, int num)
{
    int i, j;

    printf("Input the 3 scores for each student.\n");
    for (i = 0; i < num; i++)
    {
        printf("%s %s: ", stud[i].name.first, stud[i].name.second);
        for (j = 0; j < SIZE; j++)
        {
            while (scanf("%f", &stud[i].grade[j]) != 1)
            {    
                printf("Input an invalid score. Please re-enter a number: ");
                while (getchar() != '\n')
                    continue;
            }
        }
    }
    printf("Input done!\n");
}
void calc_scores(Student * stud, int num)
{
    int i, j;
    float sum;

    for (i = 0; i < num; i++)
    {
        for (j = 0, sum=0.0f; j < SIZE; j++)
        {
            sum += stud[i].grade[j];
        }
        stud[i].average = sum / SIZE;
    }
}
void show_info(const Student * stud, int num)
{
    int i, j;
    char * name;
    
    printf("%-10s %-10s %-10s\n", "Name", "Score", "Average");
    for (i = 0; i < num; i++)
    {
        name = get_name(&stud[i]);
        printf("%-10s %-10.2f %-10.2f\n", name, stud[i].grade[0], stud[i].average);
        for (j = 1; j < SIZE; j++)
            printf("%-10s %-10.2f %-10s\n", " ", stud[i].grade[j], " ");
        free(name);
    }
}
void show_average(const Student * stud, int num)
{
    float avg[CSIZE] = {0.0f};
    int i, j;

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < SIZE; j++)
            avg[j] += stud[i].grade[j];
        avg[j] += stud[i].average;
    }
    for (i = 0; i < CSIZE; i++)
    {
        if (i < SIZE)
            printf("Score %d: %.2f\n", i+1, avg[i]/CSIZE);
        else
            printf("Average: %.2f\n", avg[i]/CSIZE);
    }
}

char * get_name(const Student * stud)
{
    const char * first = stud->name.first;
    const char * second = stud->name.second;
    char * name = malloc(strlen(first) + strlen(second) + 1);
    strcpy(name, first);
    strcat(name, " ");
    strcat(name, second);

    return name;
}