#include "library.h"

int sum(const int num1, const int num2)
{
    return num1 + num2;
}

int sub(const int num1, const int num2)
{
    return num1 - num2;
}

int min(const int count, int *x)
{
    int minimum = x[0];
    for(int i = 0; i < count; i++)
    {
        if(minimum > x[i])
        {
            minimum = x[i];
        }
    }

    return minimum;
}


int max(const int count, int *x)
{
    int maximum = x[0];
    for(int i = 0; i < count; i++)
    {
        if(maximum < x[i])
        {
            maximum = x[i];
        }
    }

    return maximum;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}