#include <stdio.h>
int main()
{
    // declare and initialize variables
    double item1 = 15.95, item2 = 24.95, 
    item3 = 6.95 , item4 = 12.95, item5 = 3.95, 
    subtotal, tax, total;
    
    subtotal = item1 + item2 + item3 + item4 + item5;
    tax = subtotal * 0.07;
    total = subtotal + tax;
    
    // display prices of items
    printf("Price of item 1 = %f\n", item1);
    printf("Price of item 2 = %f\n", item2);
    printf("Price of item 3 = %f\n", item3);
    printf("Price of item 4 = %f\n", item4);
    printf("Price of item 5 = %f\n", item5);
    
    // display subtotal, sales tax, and total
    printf("The subtotal of the sale is %f and the sales tax is %f.\n", subtotal, tax);
    printf("The total is %f.\n", total);
    
    return 0;
}
