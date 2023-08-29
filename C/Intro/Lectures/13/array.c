#include <stdio.h>

int main()
{
    // initialize array and total
    double itemList[3], total = 0;

    printf("Please enter prices: ");
    
    // for loop to scan each item
    for(int i = 0; i < 3; i++)
    {
        scanf("%lf", &itemList[i]);
    }
    
    printf("Here are the prices: ");
    
    // for loop to print each price value and re-declaration of total
    for(int x = 0; x < 3; x++)
    {
        printf("%.2lf ", itemList[x]);
        total+=itemList[x];
    }

    printf("\nThe total of the listed prices is: %.2lf", total);
    
    return 0;
}
