#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    char count = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(count < 10)
            {
                printf(" %d ", count++);
            }
            else
            {
                printf("%d ", count++);
            }
        }
        printf("\n");
    }
}