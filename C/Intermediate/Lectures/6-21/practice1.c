#include <stdio.h>
#include <stdlib.h>


void main(void)
{
    int x;
    int *p;

    p = &x;

    // Assign x as 12 then as 13 since p points to address of x variable;
    x=12;
    *p=13;

    printf("x is %d\n", x);
    printf("%p is the address of x\n", p);
    printf("%p is also the address of x\n", &x);

    // Check to see if *p is pointed to address x
    if(p == &x)
    {
        printf("The address for x and the address pointer p points to are the same.\n");
    }
    else
    {
        printf("The addresses don't match.\n");
    }
}