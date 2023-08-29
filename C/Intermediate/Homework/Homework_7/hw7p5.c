// CSE 1320 Intermediate Programming
// HW7, Problem 3
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>
#include "hw7_fns.h"

int main(void)
{
    // data points to the array of "count" integers
    int *data = NULL;
    int count = 0;

    int i;

    // Add values
    addValueToArray(&data, &count, 0, 11);
    addValueToArray(&data, &count, 1, 12);
    addValueToArray(&data, &count, 0, 9);
    addValueToArray(&data, &count, 0, 13);
    addValueToArray(&data, &count, 0, 9);
    addValueToArray(&data, &count, 0, 99);
    addValueToArray(&data, &count, 0, 30);
    addValueToArray(&data, &count, 0, 9);
    addValueToArray(&data, &count, 0, 13);
    addValueToArray(&data, &count, 0, 13);
    addValueToArray(&data, &count, 3, 20);

    // Print values
    printf("count = %d\n", count);
    for (i = 0; i < count; i++)
        printf("data[%d] = %d\n", i, data[i]);

    // Counting number of 9s
    printf("\nNumber of 9s = %d\n", countValueInArray(data, count, 9));

    // Free memory
    free(data);
    return EXIT_SUCCESS;
}
