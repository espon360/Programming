// CSE 1320 Intermediate Programming
// Mymath (Local library of math fns)
// Requires C99 (use -std=c99 option or works by default with GCC)

#ifndef _MYMATH_H_

#define _MYMATH_H_

// Returns the minimum value in an array of count entries
// result only defined if count > 0
int min(const int x[], int count);

// Returns the maximum value in an array of count entries
// result only defined if count > 0
int max(const int x[], int count);

// Bubble sort
// Integers are stores in an increased order in-place
void sort(int x[], int count);

#endif

// this code includes an include guard that ensures that the min and
// max functions are only declared once

