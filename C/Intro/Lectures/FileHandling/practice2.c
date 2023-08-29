#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char letter;

    FILE *fptr;

    fptr = fopen("test.txt", "r");

    if(fptr == NULL)
    {
        printf("ERROR!!! File not found.");
        exit(1); // similar to return 0
    }

    // three arguments are (fptr, "datatype", variable saved to)
    fscanf(fptr, "%c", &letter);
    // scanning character from fptr onto letter
    printf("The 1st letter from the file is: %c\n", letter);

    // next fscanf will read next letter
    fscanf(fptr, "%c", &letter);
    printf("The 2nd letter from the file is: %c\n", letter);

    fclose(fptr); // close fptr
    
    return 0;
}