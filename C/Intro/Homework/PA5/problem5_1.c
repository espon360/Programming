#include <stdio.h>

void main()
{
    int decimal, test, binary[100], x = 0;
    
    // Get user input for decimal and retain original value of decimal in test
    do
    {
        printf("Please enter a decimal (base 10) number: ");
        scanf("%d", &decimal);
        test = decimal;
    } while (decimal < 0);
    
    // Assign binary array
    while(decimal / 2 != 0)
    {
        binary[x] = decimal % 2;
        decimal /= 2;
        x++;
    }
    
    // Reassign final array value to 1 if not 0
    if(test != 0)
    {
        binary[x] = 1;
    }
    
    while(x >= 0)
    {
        printf("%d", binary[x]);
        x--;
    }
}
