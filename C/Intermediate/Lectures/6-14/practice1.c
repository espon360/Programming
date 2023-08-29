#include <stdio.h>
#include <stdlib.h>

/* Write a C Program that prints a 2x3 array of integers with
each number incrementing by one */

#define R 3
#define C 5

void main()
{
    char count = 0;

    // Check to see if number of rows is positive or negative
    if(R <= 0 || C <= 0)
    {
        printf("The number of rows / columns is invalid.");
    }

    for(char i = 0; i < R; i++)
    {
        for(char j = 0; j < C; j++)
        {
            printf("%d ", count++);
        }
        printf("\n");
    }
}