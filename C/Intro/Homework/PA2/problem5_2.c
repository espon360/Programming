#include <stdio.h>
int main()
{
    // declare variables
    float actual, assessment, tax;
    
    // ask for user to input actual value of property
    printf("Please enter the actual value of the property: \n");
    scanf("%f", &actual);
    
    // initialize assessment and display value
    assessment = actual * 0.6;
    printf("The assessment value is: %f.\n", assessment);
    
    // initialize tax and display value
    tax = 0.75 * (assessment / 100);
    printf("The property tax is: %f.\n", tax);
    
    return 0;
}
