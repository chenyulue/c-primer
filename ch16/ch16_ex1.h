#ifndef CH16_EX1
#define CH16_EX1
#include <stdbool.h>
#include <time.h>

#define HMEAN(X,Y) (2/(1/(X) + 1/(Y)))
#define PI 3.1415926

typedef struct polar_st {
    double magnitude;
    double angle;
} Polar;

typedef struct rect_st {
    double x;
    double y;
} Rect;

Rect polarToRect(const Polar * polar);

bool delay(double duration, const clock_t * start);

void choice(const int arr[], size_t size, int pick_num);

typedef struct names {
    char first[20];
    char last[20];
} Name;

#endif