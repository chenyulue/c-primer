#include <stdio.h>

int main(void)
{
    char line[255], current;
    int idx, count;

    printf("Enter a line of string:\n");
    for (idx = 0, count = 0, scanf("%c", &line[idx]); 
         line[idx] != '\n'; scanf("%c", &line[idx]))
    {
        idx++;
        count++;
    }
    for (idx = count - 1; idx >= 0; idx--)
        printf("%c", line[idx]);
    printf("\n");

    return 0;
        
}