/*Write a function that takes two strings as input and returns 1 
if the strings are equal and 0 otherwise. (you can utilize string library functionalities */

#include <stdio.h>
#include <string.h>

int compareString()
{
    char string1[1000], string2[1000];
    printf("Please enter the first string: ");
    scanf("%s", string1);
    
    printf("Please enter the second string: ");
    scanf("%s", string2);

    int result = strcmp(string1, string2);
    
    printf("%d", result);

    return strcmp(string1, string2) == 0;
}

void main()
{
    int result = compareString();
    if(result == 1)
    {
        printf("The strings are the same.\n");
    }
    else
    {
        printf("The strings are different.\n");
    }
}