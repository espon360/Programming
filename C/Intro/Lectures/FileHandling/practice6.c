// Comparing two files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Access files through function calls
void compareFiles(FILE *file1, FILE *file2);
int main()
{
    // Declaration and Initialization of file at same time
    FILE *f1 = fopen("test.txt", "r");
    FILE *f2 = fopen("test2.txt", "r");

    if(f1 == NULL || f2 == NULL) //See if both files open
    {
        printf("One or both files are not available.\n");
        exit(1);
    }

    //Function call

    compareFiles(f1, f2);

    // Close f1 and f2
    fclose(f1);
    fclose(f2);

    return 0;
}

// Function definition
void compareFiles(FILE *file1, FILE *file2)
{
    char c1 = getc(file1);
    char c2 = getc(file2);

    // Will stay in loop until end of file
    while(c1 != EOF && c2 != EOF) // same as !feof(f1) or (f2)
    {
        if(c1 != c2) // Test if characters in same position are the same
        {
            printf("The two files are not the same.\n");
            return; // Leave function completely
        }
        // Will read next character
        c1 = getc(file1);
        c2 = getc(file2);
    }

    printf("The two files are the same.\n");
}
