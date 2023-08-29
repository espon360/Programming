#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// gcc exampractice.c

int sum(int count, int *x);
float average(int count, float all);
void main()
{
    int *list;
    int i = 0;
    list = malloc(1 * sizeof(int));
    bool test = false;

    while (test == true)
    {
        list = realloc(list, sizeof(int) * (i+2));
        if(list[i] == 0)
        {
            test = true;
        }
        i++;

        #ifdef DEBUG
        printf("list[%d] is %d\n", i-1, list[i]);
        #endif
    }

    float total = sum(i-1, list);
    printf("The average of all the numbers is: %.2f\n", average(i-1, total));
}

int sum(int count, int *x)
{
    int total = 0;
    for(int i = 0; i < count; i++)
    {
        total += x[i];
    }

    return total;
}

float average(int count, float all)
{
    return all / count;
}