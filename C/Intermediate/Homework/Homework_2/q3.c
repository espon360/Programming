#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hexStringToUint(const char str[]);
void main(void)
{
    char string[4];
    int decimal, error;

    do
    {
        printf("Please type your hexadecimal number: ");
        fscanf(stdin, "%s", string);

        #ifdef DEBUG
        printf("The string is %s\n", string);
        #endif

        for(int i = 0; i < strlen(string); i++)
        {
            error = 0;
            #ifdef DEBUG
            printf("i = %d ", i);
            #endif

            if(string[i] - '0' < 0 || string[i] - '0' >= 10)
            {
                #ifdef DEBUG
                printf("%c fails first test.\n", string[i]);
                #endif
                if(string[i] < 'a' || string[i] > 'f')
                {
                    #ifdef DEBUG
                    printf("%c fails second test.\n", string[i]);
                    #endif
                    if(string[i] < 'A' || string[i] > 'F')
                    {
                        #ifdef DEBUG
                        printf("%c fails third test. \n", string[i]);
                        #endif
                        error++;
                    }
                }
            }
        }
    }while(error != 0);

    if(strlen(string) == 0)
    {
        printf("The string is empty, therefore it's value is 0.\n");
    }
    else
    {
        decimal = hexStringToUint(string);
        printf("The decimal value of %s is: %d\n", string, decimal);
    }
}

unsigned int hexStringToUint(const char str[])
{
    int sum = 0, power = 1;
    for(int i = strlen(str) - 1; i >= 0; i--)
    {
        if(str[i] - '0' >= 0 && str[i] - '0' < 10)
        {
            sum += (str[i] - '0') * power;
            power *= 16;
        }
        else if(str[i] >= 'a' && str[i] <= 'f')
        {
            sum += (str[i] - 87) * power;
            power *= 16;
        }
        else if(str[i] >= 'A' && str[i] <= 'F')
        {
            sum += (str[i] - 55) * power;
            power *= 16;
        }
    }

    return sum;
}