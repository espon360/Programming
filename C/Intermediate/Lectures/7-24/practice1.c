#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int **newMatrix(int rows, int cols)
{
    int r;
    int **m = malloc(rows * sizeof(int*));
    for(r = 0; r < rows; r++)
    {
        m[r] = malloc (cols * sizeof(int));
    }

    return m;
    // allocates an array of ints that is the size of cols into each row of *m
}

void main(void)
{
    int rows = 3, columns = 3;
}