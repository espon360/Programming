#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Check how many characters
    FILE *fptr;
    fptr = fopen("input.txt", "r");

    FILE *fptr2;
    fptr2 = fopen("output.txt", "w");

    if(fptr == NULL || fptr2 == NULL)
    {
        printf("File not found.\n");
        exit(1);
    }

    int x = 0;
    char c = fgetc(fptr);

    while(!feof(fptr))
    {
        if(c != ' ' && c != '\n')
        {
            x++;
        }
        c = fgetc(fptr);
    }

    fclose(fptr);

    // Input result into output.txt

    fprintf(fptr2, "%d\n", x);
    printf("The number of characters aside from spaces and new lines have been written into output.txt\n");

    fclose(fptr2);

    return 0;
}
