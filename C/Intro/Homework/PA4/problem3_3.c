#include <stdio.h>
int main(){

    int num, row, column, product;
    do
    {
        printf("Please enter a positive integer: ");
        scanf("%d", &num);
    } while (num <= 0);

    printf("Here is a multiplication table from 1 to %d\n\n", num);

     for(row = 1; row <= num; row++)
        {
            for(column = 1; column <= num; column++)
            {
                product = row * column;
                printf("%d ", product);
            }
            printf("\n");
        }

    return 0;
}
