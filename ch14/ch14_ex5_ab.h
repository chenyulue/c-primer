#define SIZE 3

typedef struct name_st {
    char first[40];
    char second[40];
} Name;

typedef struct student_st {
    Name name;
    float grade[SIZE];
    float average;
} Student;
