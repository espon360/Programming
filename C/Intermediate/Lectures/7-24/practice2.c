#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int *x;
    x = malloc(2*sizeof(int));

    x[0] = 10;
    x[1] = 4;

    printf("x[0] = %d and x[1] = %d\n", x[0], x[1]);

    x[1] = NULL;
    free(x[1]);
    x = realloc(x, 1 * sizeof(int));

    
    printf("x[0] = %d and x[1] = %d\n", x[0], x[1]);
    free(x);
}