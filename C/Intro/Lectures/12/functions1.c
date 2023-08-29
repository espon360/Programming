#include <stdio.h>
#include <stdio.h>

// Function prototype
double mult(double a, int b);

int main()
{
    int a = 3;
    double b = 4;
    
    // Function call
    printf("the value is: %lf\n", mult(b, a));
    return 0;
}


// Function definition
double mult(double a, int b)
{
    printf("%.3lf %d\n", a, b);
    return (a*b);
}
