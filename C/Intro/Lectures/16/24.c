/*Write a program that asks the user for the size of an integer array and then the numbers to that integer array. 
Then the program determines whether or not the array is in ascending order. 
The program should then output if the array is in ascending order or not.*/

#include <stdio.h>

void main()
{
    int size, check = 0;
    printf("Please input the size of the array: ");
    scanf("%d", &size);
    int array[size];

    for(int i = 0; i < size; i++)
    {
        printf("Please input a number for position %d: ", i+1);
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-i; j++)
        {
            if(array[i] > array[size - 1 - j])
            {
                check++;
            }
        }
    }

    if(check == 0)
    {
        printf("The numbers are in ascending order.\n");
    }
    else
    {
        printf("The numbers are not in ascending order.\n");
    }

}