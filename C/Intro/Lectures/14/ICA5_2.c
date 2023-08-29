#include <stdio.h>
/*Write a program that takes an integer array
 and reverses it into another integer array. 
 (you can do this in a function reverseArray). Your choice.*/

 void reverseArray(int matrix[3]);
 void main()
 {
    int initialArray[3];
    
    for(int i = 0; i < 3; i++)
    {
        printf("Please enter value no.%d for the array:", i+1);
        scanf("%d", &initialArray[i]);
    }

    reverseArray(initialArray);
 }

 void reverseArray(int matrix[3])
 {
    int reverse[3], position = 0;

    for(int i = 2; i >= 0; i--)
    {
        reverse[position] = matrix[i];
        position++;
    }

    printf("Here is the array you entered in reverse order:\n");
    for(int j = 0; j < 3; j++)
    {
        printf("%d ", reverse[j]);
    }
 }
 