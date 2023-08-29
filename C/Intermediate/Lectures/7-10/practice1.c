#include "practice1.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
// Need to include the header this c program is defining for

int min(const int x[], int count)
// or int min(int *x, int count)
{
	int minimum = x[0];
    // if x[0] doesn't exist, will cause segmentation error
	for (int i = 1; i < count; i++)
    // check if x[1,2,3,...] is < minimum (which is x[0]) then assigns new minimum value if true
		if (x[i] < minimum)
			minimum = x[i];
	return minimum;
}

// Returns the maximum value in an array of count entries
// result only defined if count > 0
int max(const int x[], int count)
// or int min(int *x, int count)
{
	int maximum = x[0];
	for (int i = 1; i < count; i++)
		if (x[i] > maximum)
			maximum = x[i];
	return maximum;
}