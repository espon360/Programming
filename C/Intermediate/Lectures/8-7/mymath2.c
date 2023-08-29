// CSE 1320 Intermediate Programming
// Mymath2 (Local library of math fns)
// Requires C99 (use -std=c99 option or works by default with GCC)

#include "mymath.h"
#include "mymath2.h"

// Returns the minimum value in an array of count entries
// limited to a minimum value of zero
// result only defined if count > 0
int minOrZero(int x[], int count)
{
    int y = min(x, count);
    if (y < 0)
        y = 0;
    return y;
}


