// CSE 1320 Intermediate Programming
// Minmax (Local functions to calc min and max)
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "practice1.h"

#define COUNT 5

// Returns the minimum value in an array of count entries
// result only defined if count > 0
// Since getting a min and max is a common goal needed in programming, how about we create our own library to call from?

int main(void)
{
    int x[COUNT] = {34, 52, -9, 10, 33};
    // Return minimum of array COUNT (should return -9)
    int minimum = min(x, COUNT);
    // Return maximum of array COUNT (should return 52)
    int maximum = max(x, COUNT);
    printf("Minimum = %d\n", minimum);
    printf("Maximum = %d\n", maximum);
    return EXIT_SUCCESS;
}
