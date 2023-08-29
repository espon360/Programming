/*Write a complete program, hw7.c, that can be called from the command line
using the syntax
“hw7 filename”, where filename is the file to open in the format mentioned
above.
The program should:
- Contain a preprocessor command to include the hw6_fns.h file (from the last
homework set)
- Contains a variable
char** b;
- Opens the requested file (filename)
- Has a variable to keep track of the number of businesses found in the file
- For each line of the file:
+ Read in the line of text
+ Use the getBusiness() function to extract the name from the line of text
+ Use malloc() to allocate a string to store the business name, recording the
name returned from getBusiness
+ Use malloc() and subsequently realloc(), grow “b” to add another char* to
the array, recording the string allocated above
- Close the file
- Print the businesses
- Free the memory
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hw6_fns.h"

#define MAX 200 // max characters of 200 since each line is large

void main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Incompatible number of arguments.\n");
        exit(EXIT_FAILURE);
    }

    FILE *fptr = fopen(argv[1], "r");
    if(fptr == NULL)
    {
        printf("File could not be open.\n");
        exit(EXIT_FAILURE);
    }

    char **b;
    b = malloc(1*sizeof(char*)); // allocates size for 1 char string

    int i;
    int count = 0; // for how many lines it reads
    char buffer[MAX+1];
    char temp[MAX+1];
    char *str;

    if(fgets(buffer, sizeof(buffer), fptr) == NULL)
    {
        printf("Error, could not read top line.\n");
        exit(EXIT_FAILURE);
    }

    if(fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        getBusiness(temp, buffer); // Get business name from line and temp
        str = malloc((strlen(temp)+1)*sizeof(char)); // Allocate str to the size of temp (make it the size of the business name + NULL)
        strcpy(str, temp); // Since str has enough space now, copy temp over to it
        b[count++] = str; // Assign *b at line no. (count) to str
        b = realloc(b, (count+1) * sizeof(char*)); // reallocate size for additional entry of b*
    }

    fclose(fptr); // Close file

    printf("%d records found.\n", count); // Show how many were found

    for(i = 0; i < count; i++)
    {
        free(b[i]); // Free allocated memory for the arrays in each b[i]
    }
    free(b); // Free b pointer to array
}