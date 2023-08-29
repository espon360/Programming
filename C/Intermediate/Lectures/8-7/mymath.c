// CSE 1320 Intermediate Programming
// Mymath (Local library of math fns)
// Requires C99 (use -std=c99 option or works by default with GCC)

#include "mymath.h"

// Good example, pass by reference (location of variables, not value)
void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

// Returns the minimum value in an array of count entries
// result only defined if count > 0
int min(const int x[], int count)
{
	int minimum = x[0];
	for (int i = 1; i < count; i++)
		if (x[i] < minimum)
			minimum = x[i];
	return minimum;
}

// Returns the maximum value in an array of count entries
// result only defined if count > 0
int max(const int x[], int count)
{
	int maximum = x[0];
	for (int i = 1; i < count; i++)
		if (x[i] > maximum)
			maximum = x[i];
	return maximum;
}

// Bubble sort
// Integers are stores in an increased order in-place
// indices, not values
// 0 1 2 3 4 -> count = 5
// i = count - 1 = 4
// 0 1         (j = 0) (make index 1 >= index 0)
//   1 2       (j = 1) (make index 2 >= index 1)
//     2 3     (j = 2) (make index 3 >= index 2)
//       3 4   (j = 3) (make index 4 >= index 3) x[4] is largest number
// i = 3
// 0 1         (j = 0) (make index 1 >= index 0)
//   1 2       (j = 1) (make index 2 >= index 1)
//     2 3     (j = 2) (make index 3 >= index 2) x[3] is next to largest number
// i = 2
// 0 1         (j = 0) (make index 1 >= index 0)
//   1 2       (j = 1) (make index 2 >= index 1) x[2] is 3rd largest numbner
// i = 1
// 0 1         (j = 0) (make index 1 >= index 0) x[1] is 4th largest number, x[0] is smallest
void sort(int x[], int count)
{
	int i, j;
	for (i = count-1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
			if (x[j] > x[j+1])
				swap(&x[j], &x[j+1]);
	}
}
