#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fptr;
    fptr = fopen("input.txt", "r");

    if(fptr == NULL) // Check if file does not exist
    {
        printf("Error!\n");
        exit(1);
    }

    // User inputs name
    int x = 0;
    char name[100], line[100];
    printf("Enter the name you would like to search up: ");
    fgets(name, sizeof(name), stdin);

    // Search up name
    while(!feof(fptr))
    {
        fgets(line, sizeof(line), fptr);
        if(strcmp(name, line) == 0)
        {
            x++;
        }
    }

    if(x != 0)
    {
        printf("input.txt does have that name.\n");
    }
    else
    {
        printf("input.txt does not have that name.\n");
    }

    fclose(fptr);
    
}
