#include <stdio.h>
#include <stdlib.h>
// Define amount of numbers
#define N 5

// Calculate average of numbers

void main()
{
    float x[N], sum = 0;
    for(int i = 0; i < N; i++)
    {
        printf("Please input the number in the number %d position:\n", i+1);
        fscanf(stdin, "%f", &x[i]);
        sum += x[i];
    }

    float average = sum / N;
    printf("The average of the %d number(s) is: %f", N, average);

}