#include <stdio.h>

int main(void)
{
    const int ROW = 6;
    int row, col;
    char letter;

    for (row = 0, letter = 'A'; row < ROW; row++)
    {
        for (col = 0; col <= row; col++)
            printf("%c", letter++);
        printf("\n");
    }

    return 0;
}