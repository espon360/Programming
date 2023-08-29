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

    int vowel = 0;
    char c = fgetc(fptr);

    // Check for number of vowels

    while(!feof(fptr))
    {
        if(c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' ||
        c == 'i' || c == 'O' || c =='o' || c == 'U' || c == 'u')
        {
            vowel++;
        }
        c = fgetc(fptr);
    }

    fprintf(fptr2, "%d\n", vowel);
    printf("The number of vowels has been written into output.txt\n");

    fclose(fptr);
    fclose(fptr2);

}