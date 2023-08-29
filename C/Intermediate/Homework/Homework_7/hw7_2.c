/*Write a function, void addValueToArray(int **x, int *count, int index, int value),
that accepts a pointer to variable specifying a pointer to a dynamically allocated
array of integers (x) containing *count entries, a value to insert (value), and the
offset (index) for insertion. The function should grow the array dynamically to
make room to insert the new data value and then increment the count value
passed by reference to the function. To emphasize this again, this function will
add the value to the array, changing the array and the count in the process.*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hw6_fns.h"

#define MAX 200 // max characters of 200 since each line is large

// main function should have: int *(variable) and &(variable) will be used as argument for addValueToArray function
// addValueToArray should basically insert an int "value" to an array *x at placement "index"
// **x is the pointer to array of ints, *count is the pointer to the numer of indexes at each array

void addValueToArray(int **x, int *count, int index, int value);
// **x is asking for address to an array of int 

void main(int argc, char* argv[])
{

}

void addValueToArray(int **x, int *count, int index, int value)
{
    // usage: &x is the address for (variable) in main
}