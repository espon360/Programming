#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 80

// usage: practice1, name of file, value of file
// name of file is file to open
// value of file is integer to find and count in file
// file contains one integer per line in this case

int main(int argc, char* argv[])
{
    // Step one: Validate number of arguments is valid
    if (argc != 3)
    {
        // number of arguments isn't 3 and tells user how to format the command
        printf("Too few or too many arguments\n");
        printf("Usage should read: practice1 filename value\n", argc);
        exit(EXIT_FAILURE);
    }

    // Step two: Store value to find
    int value = atoi(argv[2]);

    // Step three: Open file

    // Open file argv[1] in read only
    FILE *file = fopen(argv[1], "r");
    // Test if file could open
    if (file == NULL)
    {
        printf("File %s could not be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Step four: Initialize count
    int count = 0;

    // Step five: parse file and increment count after each line that reads searched integer
    // buffer is basically just a placeholder for where to place memory into
    char buffer[MAX_CHARS_PER_LINE+1];
    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
        int temp = atoi(buffer);
        // turns ascii for string of buffer AKA argv[1] to integer value
        if (temp == value)
        {
            count++;
            // increment count if buffer matches value you search
        }
    }
    // Basically says go to file, copy string in line to buffer with only MAX CHARS size+1
    // buffer has 81 characters size
    // Will get each string until it reaches a NULL

    // Step six: printf text of how many is in count

    printf("Found %d occurences of %d in file %s\n", count, value, argv[1]);

    // Step seven: close file
    fclose(file);
}
/* To recap, this will look like this on terminal: .\practice1 "Name of text file" integer you're searching */