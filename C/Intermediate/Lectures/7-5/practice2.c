#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 80

// usage: practice1, name of file, value of file
// name of file is file to open
// value of file is integer to find and count in file

// Program will find all unique integers in given file and print it back to the user
// Static memory compilation (you set the size of in memory allocated during coding phase rather than while the program is running)
// Dynanmic memory copilation: size of array / pointer is adjusted as the program is running

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

    char buffer[MAX_CHARS_PER_LINE+1];
    char* token; //sub string within a string
    char delim[] = " \t,"; // limit each miniature string to what ever you want to 
    // in the case of this delimiter, we are making the limit a ' ' a tab (\t) and a ','
    int temp;
    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
#ifdef DEBUG
    printf("fgets() returns %s\n", buffer);
    // Will printf out what was scanned in each line
#endif

        token = strtok(buffer, delim); // strtok is basically taking the mini string and just sends you that minus everything past delimiter
        while (token != NULL)
        {
            #ifdef DEBUG
            printf("strtok() returned %s\n", token);
            // Will printf off what was the token that was read
            #endif
            temp = atoi(token); // set temp to the token integer value
            if (temp == value)
            {
                count++;
            }

            token = strtok(NULL, delim); // NULL in strtok is basically telling you to keep using the token you were using
            // NULL is telling you to go to the next token / ministring
        }
    }

    // Step six: printf text of how many is in count

    printf("Found %d occurences of %d in file %s\n", count, value, argv[1]);

    // Step seven: close file
    fclose(file);
}
/* To recap, this will look like this on terminal: .\practice1 "Name of text file" integer you're searching */