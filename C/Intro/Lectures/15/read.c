#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letter;

    FILE *fptr; //Declare pointer variable
    // Don't need to use "*" after declaring pointer

    fptr = fopen("text.txt", "r");
    // Point to and open text.txt and read it

    if(fptr == NULL)
    {
        printf("ERROR! File not in directory.\n");

        exit(1); // similar to return 0 (basically exits file)
    }

    // Read letter from file
    fscanf(fptr, "%c", &letter); // Scanf from fptr

    printf("The letter from the file is %c.\n", letter);


    fclose(fptr); // Close file
    return 0;
}
