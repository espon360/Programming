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
    
    while(!feof(fptr))
    {
        fscanf(fptr, "%c", &letter);
        printf("%c", letter);
    } 
    // feof means check for end of file in fptr
    // feof returns 1 if 
    fclose(fptr);

    return 0;
}