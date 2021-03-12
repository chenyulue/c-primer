#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

char * itobs(unsigned int num, char * ps);
unsigned int rotate_l(unsigned int num, int dist);
bool is_on_at(int number, int position);

const static int size = CHAR_BIT * sizeof(unsigned int);

int main(void)
{
    unsigned int num, offset;
    char ps[size + 1];

    while (scanf("%u %u", &num, &offset) == 2)
    {
        unsigned int rotate = rotate_l(num, offset);
        printf("%20u = %s\n", num, itobs(num, ps));
        printf("%20u = %s\n", rotate, itobs(rotate, ps));
    }

    return 0;
}

char * itobs(unsigned int num, char * ps)
{
    int i;
    for (i = size - 1; i >= 0; i--, num >>= 1)
        ps[i] = (01 & num) + '0';
    ps[size] = '\0';

    return ps;
}

unsigned int rotate_l(unsigned int num, int dist)
{
    unsigned int rl = num << dist;
    unsigned int mask = 1 << size - 1;
    unsigned int out = 0;

    for (int i = 0; i < dist; i++, num <<= 1)
    {
        if (mask & num)
            out = out * 2 + 1;
        else
            out = out * 2;
    }

    return rl | out;

}

bool is_on_at(int number, int position)
{
    return 01 & (number >> (position - 1));
}