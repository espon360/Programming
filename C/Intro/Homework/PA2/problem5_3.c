#include <stdio.h>
int main()
{
    // declare variables
    float t1, t2, t3, t4, t5, average;
    
    // ask user to enter 5 tests
    printf("Please enter 5 test scores (put a space between each number):\n");
    scanf("%f %f %f %f %f", &t1, &t2, &t3, &t4, &t5);
    
    // initialize average and display
    average = (t1+t2+t3+t4+t5) / 5;
    printf("The average is: %0.1f.\n", average);
    
    return 0;
}

