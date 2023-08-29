#include <stdio.h>
int main(){
    int num, row, column;
    do
    {
        printf("Please enter a positive integer: ");
        scanf("%d", &num);
    } while (num <= 0);

    printf("Here is a square with the dimensions %dx%d.\n", num, num);

    for(row = 1; row <= num; row++)
        {
            for(column = 1; column <= num; column++)
            {
                printf("*");
            }
            printf("\n");
        }

    return 0;
} 
