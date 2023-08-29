#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// gcc exampractice.c

void multiplication(const int count, char* x[]);
int check(char fileName[], char num[]);
void main(int argc, char* argv[])
{
    char response;
    printf("Please enter the tool you wish to run:\n");
    printf("(1 = Multiply) (2 = Check)\n");
    fscanf(stdin, "%d", &response);

    switch(response)
    {
        case 1:
        multiplication(argc, argv);
        break;

        case 2:
        int count = check(argv[1], argv[2]);
        printf("The number of times \'%s\' appeared in file \'%s\' is: %d\n", argv[2], argv[1], count);
    }
}

void multiplication(const int count, char* x[])
{
    // If usage is: .\file.exe 'num1' 'num2' ...
    int product = 1, value, i;

    for(i = 1; i < count; i++)
    {
        value = atoi(x[i]);
        product *= value;

        #ifdef DEBUG
        printf("value = %d / product = %d\n", value, product);
        #endif
    }

        #ifdef DEBUG
        printf("count = %d\n", count);
        #endif

    printf("The product of the arguments is: %d\n", product);
}

int check(char fileName[], char num[])
{
    FILE *fptr = fopen(fileName, "r");
    if(fptr == NULL)
    {
        printf("ERROR! Could not open \'%s\'...\n", fileName);
        exit(EXIT_FAILURE);
    }

    char buffer [100];
    char *token;
    char delim[] = " \t,";
    int value = atoi(num);
    int temp, count = 0;
    while(fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        token = strtok(buffer, delim);
        while(token != NULL)
        {
            temp = atoi(token);
            if(temp == value)
            {
                count++;
            }
            token = strtok(NULL, delim);
        }
    }

    fclose(fptr);
    return count;
}