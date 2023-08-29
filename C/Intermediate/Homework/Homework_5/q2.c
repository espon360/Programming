/*Write a C function, unsigned int countMatching(const char fileName[], const char
match[]), that opens the requested file (fileName), counts the total number of
matching strings in the file, closes the file, and returns the count. You can
assume that each string is on a separate line.*/

/*Write a C program (count_match) that can be called with the file name and
matching string as an argument. The program should then call the function in
(3) and display the number of matching strings found.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned int countMatching(const char fileName[], const char match[]);
void main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("ERROR! Too few or too many arguments...\n");
        exit(EXIT_FAILURE);
    }

    // Function call (argv[1] is the fileName, argv[2] is the string you're looking up)
    printf("The number of times \"%s\" appears is: %u\n", argv[2], countMatching(argv[1], argv[2]));
}

unsigned int countMatching(const char fileName[], const char match[])
{
    FILE *fptr = fopen(fileName, "r");

    if (fptr == NULL)
    {
        printf("ERROR! Could not open file...\n");
        exit(EXIT_FAILURE);
    }

    unsigned int count = 0;
    int test;
    char line[50];

    while(fgets(line, sizeof(line), fptr) != NULL)
    {
        // replace \n at end of each line with a terminating null

        if(line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }

        test = strcmp(line, match);
        if(test == 0)
        {
            count++;
        }
    }
    
    fclose(fptr);
    return count;
}