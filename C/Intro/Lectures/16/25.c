/*Write a function that takes an array of integers and its size as input, 
and returns the largest integer in the array.*/

#include <stdio.h>
void main()
{
    int size, max;
    printf("Please input the size of your array: ");
    scanf("%d", &size);

    int array[size];
    for(int i = 0; i < size; i++)
    {
        printf("Please enter the digit in position %d: ", i+1);
        scanf("%d", &array[i]);
    }

    max = array[0];

    for(int i = 0; i < size; i++)
    {
        if(max < array[i])
        {
            max = array[i];
        }
    }

    printf("The largest number in the array is %d.\n", max);
}