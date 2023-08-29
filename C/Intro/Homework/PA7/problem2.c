#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fptr;
    fptr = fopen("input.txt", "r");

    FILE *fptr2;
    fptr2 = fopen("output.txt", "w");

    if(fptr == NULL || fptr2 == NULL)
    {
        printf("File not found.\n");
        exit(1);
    }

    int i = 0;
    char text[1000];

    // Read each character in fptr
    while(!feof(fptr))
    {
        text[i] = fgetc(fptr);
        i++;
    }

    i = i - 2;

    // Write each character from text[] backwards into fptr2
    while(i >= 0)
    {
        fprintf(fptr2, "%c", text[i]);
        i--;
    }

    printf("The sentence in input.txt has been written backwards in output.txt");

    fclose(fptr);
    fclose(fptr2);

}