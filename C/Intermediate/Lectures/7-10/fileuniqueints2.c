// CSE 1320 Intermediate Programming
// Fileuniqueints 2 (Find and print all unique values in a file)
// Requires C99 (use -std=c99 option or works by default with GCC)

// Dynamic memory allocation of unique value storage

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS_PER_LINE 80

// usage: fileuniqueints filename
// filename is the file to open
// file contains multiple integers per line
int main(int argc, char* argv[])
// char* argv[] basically points to file for when you run the program in terminal (.\"program.exe" "argv[1] / filename")
{
    // Validate number of arguments
	if (argc != 2)
	{
		printf("Too few or too many arguments\n");
        printf("Usage: fileuniqueints filename\n");
        exit(EXIT_FAILURE);
	}
	
	// Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
		printf("File could not be opened\n");
        exit(EXIT_FAILURE);
    }
    
    // Zero count of number of unique integers found
    int count = 0;

    // Statically allocated space to store 1 unique integer since you have no data yet
    // At lease allocate the first int in case the data it is taking isn't empty

    int *uniqueValues = malloc(1*sizeof(int));
    // If no memory, close the open file and exit the program
    if (uniqueValues == NULL)
    {
        fclose(file);
    	exit(EXIT_FAILURE);
    }
    
    // Parse file
    char buffer[MAX_CHARS_PER_LINE+1];
    char* token;
    char delim[] = " \t,";
    int value;
    bool found; // bool value to be used to assign true or false (without)
    int i;
    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
    	token = strtok(buffer, delim);
    	while(token != NULL)
    	{
    		// get value of token
			value = atoi(token);
			// try to add value to the list of unique integers
			found = false;
			i = 0;
			while (!found && i < count)
			    found = (value == uniqueValues[i++]);
			if (!found)
			{
				// add value to dynamic array
				uniqueValues[count++] = value;
				// increase size of array by one integer to prepare for new new value

                // uniqueValues will have space allocated now for another value

                /* it does this by incrementing count and having that be multiplied by the size of int to 
                point towards next space in memory */

                /* If it accidentally runs out of space and hits another int in memory, it will just move the entire array 
                to the next freed up space */

                // Notice that this calls realloc instead of malloc, that's because we are resizing the array size
                // realloc("pointer", "allocated size you're adding for pointer")

                uniqueValues = realloc(uniqueValues, (count+1)*sizeof(int));				
                // If no memory, close the open file and exit the program
                if (uniqueValues == NULL)
                {
                    fclose(file);
                	exit(EXIT_FAILURE);
                }
			}
			// get next token
			token = strtok(NULL, delim);
    	}
    }
    
    // Close file
    fclose(file);
    
    // Print number of unique integers
    printf("Found %d unique integers in file %s\n", count, argv[1]);
    printf("Unique values in the order they appeared in the data file:\n");
    for (i = 0; i < count; i++)
    	printf("%d\n", uniqueValues[i]);
    
    // Free memory
    // AN ABSOLUTE MUST LIKE HOW YOU NEED TO CLOSE FILE
    // Failure to do this will leave that space of integers still allocated
    free(uniqueValues);
    
    return EXIT_SUCCESS;
}
