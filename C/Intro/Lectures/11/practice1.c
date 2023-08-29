#include <stdio.h>
int main()
{
    int num;

    do
    {
        printf("Please enter a positive integer: ");
        scanf("%d", &num);
    } while (num <= 0);
    
    int row, column;

    for(row = 1; row <= num; row++)
    {
        for(column = 1; column <= row; column++)
        {
            printf("%d ", column);
        }
        printf("\n");
    }

    return 0;
}
