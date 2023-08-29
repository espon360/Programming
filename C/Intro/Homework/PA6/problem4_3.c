#include <stdio.h>

void main()
{
    int x;
    do
    {
        printf("Please input the array size: ");
        scanf("%d", &x);
    } while (x <= 0);
    
    int arr1[x], arr2[x];

    // Get use input for both arrays
    for(int i = 0; i < x; i++)
    {
        printf("Please enter the value of position %d in the 1st array: ", i+1);
        scanf("%d", &arr1[i]);
        printf("Please enter the value of position %d in the 2nd array: ", i+1);
        scanf("%d", &arr2[i]);
    }

    // Compare arrays
    int diff = 0;
    for(int j = 0; j < x; j++)
    {
        if(arr1[j] != arr2[j])
        {
            diff++;
        }
    }

    switch(diff == 0)
    {
        case 1:
        printf("The arrays are the same.\n");
        break;

        case 0:
        printf("The arrays are different.\n");
        break;
    }
    
}