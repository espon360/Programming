#include <stdio.h>
int main ()
{
    int num, row, column, space;

    do
    {
        printf("Please enter a positive integer: ");
        scanf("%d", &num);
    } while (num <= 0);
    

    for(row = 0; row <= (num - 1); row++)
        {
            for(space = num; (space + row) > num; space--)
            {
                printf(" ");
            }
            for(column = 1; column <= (num - row); column++)
            {
                printf("*");
            }
            printf("\n");
        }

    return 0;  
}
