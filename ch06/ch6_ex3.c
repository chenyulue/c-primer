#include <stdio.h>

int main(void)
{
    const int ROW = 6;
    int row, col;
    char letter;

    for (row = 0, letter = 'F'; row < ROW; row++)
    {
        for (col = 0; col <= row; col++)
        {
            printf("%c", letter--);
        }
        letter = 'F';
        printf("\n");
    }

    return 0;
}