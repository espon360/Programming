#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fptr = fopen("file1.txt", "r");

    if(fptr == NULL)
    {
        printf("ERROR! File not found or could not be opened. Exitting now...\n");
        exit(EXIT_FAILURE);
    }

    int product = 1, value;
    char buffer [50];
    char* token;
    char delim[] = " \t,";

    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        token = strtok(buffer, delim);
        while(token != NULL)
        {
            value = atoi(token);
            product *= value;
            token = strtok(NULL, delim);
        }
    }
    printf("The product is %d\n", product);
}