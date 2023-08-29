// CSE 1320 Intermediate Programming
// Argtest example
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>  // EXIT_ codes
#include <stdio.h>   // printf

// usage: argtest arg0 arg1 ... argN-1
// argc is the count of arguments (including ./argtest)
// argv is an array of pointers to characters
// argv[0] has the address of the first character in the 0th argument
// argv[1] has the address of the first character in the 1st argument
// ...
int main(int argc, char* argv[])
{
    printf("Number of arguments = %d\n", argc);
    int i;
    for (i = 0; i < argc; i++)
        printf("Argument %d = %s\n", i, argv[i]);
    for (i = 0; i < argc; i++)
        printf("Address of first character in argument %d = %p\n", i, argv[i]);
    return EXIT_SUCCESS;
}

