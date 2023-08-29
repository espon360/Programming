#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primeNumber(int x);
void main(void)
{
    // position can be adjusted to any positive number of prime numbers desired
    unsigned char count = 1;
    int position = 25, i = 0;

    if(position > 0)
    {
        printf("The first %d prime number(s) is/are:\n");
    }
    else
    {
        printf("ERROR! Invalid input, exitting program now...");
    }

    while(i < position)
    {
        if(primeNumber(count) == 1)
        {
            printf("%d ", count);
            i++;
        }
        count++;
    }
}

int primeNumber(int x)
{
    unsigned char remainder, check = 0;

    for(int j = 1; j <= x; j++)
    {
        remainder = x % j;
        if(remainder == 0)
        {
            check++;
        }
    }

    if(check == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}