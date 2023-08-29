/*Write a C function, unsigned int countOdd(const char fileName[]), that opens the
requested file (fileName), counts the total number of odd numbers in the file,
closes the file, and returns the count. You can assume that each number is on a
separate line*/

/*Write a C program (count_odd) that can be called with the file name as an
argument. The program should then call the function in (1) and display the
number of odd numbers found.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS_PER_LINE 80

unsigned int countOdd(const char fileName[]);
void main(int argc, char *argv[])
{
    // Only two arguments needed since it's only asking for a single text file and the executable
	if (argc != 2)
	{
		printf("Too few or too many arguments\n");
        printf("Usage: fileuniqueints filename\n");
        exit(EXIT_FAILURE);
	}

    const char *fileName = argv[1];

    // Function call
    printf("The number of odd numbers in the file is: %u", countOdd(argv[1]));
}

unsigned int countOdd(const char fileName[])
{
    // Open file name
    FILE *fptr = fopen(fileName, "r");

    // Check if file opened correctly
    if(fptr == NULL)
    {
        printf("ERROR! File not found or could not be opened. Exitting now...\n");
        exit(EXIT_FAILURE);
    }

    unsigned int count = 0;
    int value;
    // size of string is MAX_CHARS_PER_LINE + 1 (for the null)
    char buffer[MAX_CHARS_PER_LINE + 1];

    while(fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        value = atoi(buffer);
        if(value % 2 == 1)
        {
            count++;
        }
    }

    fclose(fptr);
    return count;
}