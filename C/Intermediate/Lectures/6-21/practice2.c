#include <stdio.h>
#include <stdlib.h>

//*x is same as x[]
int sum(const int *x);
void main(void)
{
    int x[5] = {1,2,3,4,5};
    printf("Sizeof(int) = %d\n", (int)sizeof(int));
    // Will print the size of the int in bytes

    // The (int)prior to size of will recast the size of as a an int variable

    printf("Sizeof(x[0] = %d\n", (int)sizeof(x[0]));
    // Will print 4 since size of single int x[0] in address is 4

    printf("Sizeof(x) = %d\n", (int)(sizeof(x)));
    // Will print 20 since size of all 5 variables in x is size 4

    printf("Addressof(x) = %p\n", x);
    // Print address of x (x[0])

    // Print array and it's value and corresponding address of each variable in array x
    for(int i = 0; i < 5; i++)
    {
        printf("x[%d] = %d, &x[%d] = %p\n", i, x[i], i, &x[i]);
    }

}
