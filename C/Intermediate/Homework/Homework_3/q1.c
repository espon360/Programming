#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    // &x[0] = 000000e27abffa90

    float x[10] = {0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
    float *p = &x[1];
    float *p2 = p+2;
    printf("%p\n", x);
    printf("%f\n", x[0]);
    printf("%f\n", x[1]);

    printf("%p\n", p);
    printf("%p\n", &x[3]);

    printf("%p\n", p2);
    printf("%f\n", *p2);

    printf("%p\n", p2+3);
    printf("%f\n", *(p2+3));

/*
    printf("%p\n", &x[5]);

    printf("%d\n", sizeof(x));

    printf("%p\n", *p2);
    */
}