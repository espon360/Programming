#include <stdio.h>
#include <stdlib.h>

unsigned int timesPowerOf2(unsigned int x, unsigned int p);
void main()
{
    // Adjust original and power to what you want to multiply by
    unsigned int original = 1, power = 1;

    int product = timesPowerOf2(original, power);
    printf("The product of %u times 2 to the %u th power is: %u", original, power);
}

unsigned int timesPowerOf2(unsigned int x, unsigned int p) {
    if (p == 0) 
    {
        return x;  
    } 
    else 
    {
        return x << p;  
    }
}