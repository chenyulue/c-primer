#include <stdio.h>
#include "pe12-2b.h"

int main(void)
{
    int mode, code;
    double distance, fuel;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &code);
    while (code >= 0)
    {
        set_mode(&mode, &code);
        get_info(&mode, &distance, &fuel);
        show_info(&mode, &distance, &fuel);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &code);
    }

    return 0;
}