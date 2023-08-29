#include <stdio.h>
#include <string.h>

/*Write a function named mergeArrays that
takes two character arrays as arguments, and 
prints a new array that contains all the elements of 
both arrays. */

int mergeArrays(char x[], char y[])
{
    strcat(x, y);
    puts(x);

    return strlen(x);
}

void main()
{
    char x[10], y[10];
    int length;
    gets(x);
    gets(y);

    mergeArrays(x, y);
}
