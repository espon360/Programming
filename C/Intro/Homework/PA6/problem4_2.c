#include <stdio.h>
#include <string.h>

void main()
{
    // Get string and character input from user
    char array[100], test;
    printf("Please enter a string array: ");
    gets(array);

    printf("Which character do you want to search for: ");
    scanf("%c", &test);

    // Count instances of character
    int count = 0;
    for(int i = 0; i < strlen(array); i++)
    {
        if(array[i] == test)
        {
            count++;
        }
    }

    printf("The number of times %c occurred was: %d.\n", test, count);

}
