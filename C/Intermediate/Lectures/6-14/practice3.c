#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write program to take a string of characters and convert them to an integer

// #define DEBUG

void main(void)
{
    char str[] = "12345";
    int x = 0, power = 1, sum = 0;

    for(int i = strlen(str) - 1; i >= 0; i--)
    {
        x = str[i] - '0';
        #ifdef DEBUG // Debugging (-D DEBUG to define DEBUG and run)
        printf("x is %d\n", x);
        printf("i is %d\n", i);
        printf("strlen is %d\n", strlen(str));
        #endif // Block between ifdef and endif is the Debugging to see issues
        x *= power;
        sum += x;
        power *= 10;
    }

    printf("The scanned string is %d in integers.", sum);
}