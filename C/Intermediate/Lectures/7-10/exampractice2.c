// Make library for adding, subtracting, finding min, max, swap, and sort

#include "library.h"
#include <stdio.h>


#define SIZE 4

/* Functions:
- int sum(const int num1, const int num2)
- int sub(const int num1, const int num2)

- int min(const int count, int *x)
- int max(const int count, int *x)
*/

void main()
{
    int x[SIZE] = {1,3,4,2};

    printf("%d + %d = %d\n", x[0], x[1], sum(x[0], x[1]));
    printf("%d - %d = %d\n", x[2], x[3], sub(x[2], x[3]));

    printf("The lowest number in the array is: %d\n", min(SIZE, x));
    printf("The highest number in the array is: %d\n", max(SIZE, x));

    swap(&x[0], &x[1]);
    printf("The new array after swap is: ");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", x[i]);
    }
}