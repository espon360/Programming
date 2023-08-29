// CSE 1320 Intermediate Programming
// HW6+Extras
// Parse CSV File with double-quoted fields
// dynamic allocation of array of Business structs
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hw6_fns.h"

#define MAX_CHARS_PER_LINE 200

typedef struct _Business
{
    char business[70];
    char address[90];
    char contact[40];
} Business;

int main(int argc, char* argv[])
{
    FILE *file;
    Business* b;
    int i;
    int count = 0;
    char buffer[MAX_CHARS_PER_LINE+1];
    // Check argument count
    if (argc < 3)
    {
        printf("Not enough arguments\n");
        exit(EXIT_FAILURE);
    }
    // Open file
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file\n");
        exit(EXIT_FAILURE);
    }
    // Allocate array with one business structure
    b = malloc(1*sizeof(Business));
    // Read in each line and store fields in structure
    // Resize array in anticipation of adding next structure
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        getBusiness(b[count].business, buffer);
        getAddress(b[count].address, buffer);
        getContact(b[count++].contact, buffer);
        b = realloc(b, (count+1)*sizeof(Business));
    }
    // Close file
    fclose(file);
    
    // Print out business instruction information
    printf("%d records found\n\n", count);
    printf("0: %s\n", argv[0]);
    printf("1: %s\n", argv[1]);
    printf("2: %s\n", argv[2]);
    
    for (i = 0; i < count; i++)
    {
    	if (strcmp(argv[2], "all") == 0 || strncmp(argv[2], b[i].business, strlen(argv[2])) == 0)
    	{
			printf("Business: %s\n", b[i].business);
			printf("Address:  %s\n", b[i].address);
			printf("Contact:  %s\n\n", b[i].contact);
    	}
    }
    // Write business information to file
    file = fopen("output.txt", "w");
    if (file == NULL)
    {
        printf("Could not open file to write\n");
        free(b);
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < count; i++)
    {
        fprintf(file, "Business: %s\n", b[i].business);
        fprintf(file, "Address:  %s\n", b[i].address);
        fprintf(file, "Contact:  %s\n\n", b[i].contact);
    }
    fclose(file);
    free(b);
    return EXIT_SUCCESS;
}

