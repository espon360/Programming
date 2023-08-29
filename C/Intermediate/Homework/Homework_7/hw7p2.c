// CSE 1320 Intermediate Programming
// HW7, Problem 1
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hw7_fns.h"

#define MAX_CHARS_PER_LINE 200

int main(int argc, char* argv[])
{
    FILE *file;
    char **b;
    int i;
    int count = 0;
    char buffer[MAX_CHARS_PER_LINE+1];
    char temp[MAX_CHARS_PER_LINE+1];
    char *str;
    // Check argument count
    if (argc < 2)
    {
        printf("Not enough arguments\n");
        exit(EXIT_FAILURE);
    }
    // Open file
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Coulf not open file\n");
        exit(EXIT_FAILURE);
    }
    // Allocate one char* in array
    b = malloc(1*sizeof(char*));
    if (fgets(buffer, sizeof(buffer), file) == NULL)
    {
        // Actually in part 1, we skipped the first line to
        // check if the file has some content in it
        printf("Error reading top line\n");
        exit(EXIT_FAILURE);
    }

    // We know the file has some content, so we can rewind
    fseek(file, 0, SEEK_SET);

    // Read in each line and store business string
    // Resize array in anticipation of adding next char*
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        getBusiness(temp, buffer);

        // A tiny bit wasteful but it is simple to understand
        // Before every insert, check if the string already exists in the array
        // If it is, go straight to the next loop iteration
        if (existedInArray(b, count, temp))
            continue;

        // Otherwise, add it to the array
        str = malloc((strlen(temp)+1)*sizeof(char));
        strcpy(str, temp);
        b[count++] = str;
        b = realloc(b, (count+1)*sizeof(char*));
    }
    // Close file
    fclose(file);
    // Print business names
    printf("%d records found\n\n", count);
    for (i = 0; i < count; i++)
    {
        printf("Business: %s\n", b[i]);
    }
    // Release memory
    for (i = 0; i < count; i++)
        free(b[i]);
    free(b);
    return EXIT_SUCCESS;
}

