#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    FILE *fptr;

    // Open test.txt and read
    fptr = fopen("test.txt", "r");

    char content[1000];

    if(fptr != NULL) // If file opened not failure
    {
        fgets(content, 1000, fptr); /*fgets reads content of size 1000
        with fptr of test.txt , fgets can only read one line at a time*/
        printf("%s", content); // Print test.txt that was read by content
    }
    else
    {
        printf("File Open Unsuccessful");
    }

    /*To read all of test.txt, use a while loop with conditions 
    as fgets (since it test if file read successfully). 
    The fgets will read one line then the next*/
}