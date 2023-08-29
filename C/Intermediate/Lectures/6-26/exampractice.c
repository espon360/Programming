#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// gcc exampractice.c

void main()
{
    int x = 3 << 3;
    // 3 = 0000 0011 shift left 3 would be 0001 1000 (or 24)
    printf("x = %d\n", x);

    int y = 28 & 9;
    // 28 = 0001 1100 , 9 = 0000 1001 , 28 & 9 = 0000 1000 (or 8)
    printf("y = %d\n", y);

    int z = 28 | 21;
    // 28 = 0001 1100 , 21 = 0001 0101 , 28 | 21 = 0001 1101 (or 29)
    printf("z = %d\n", z);

    int a = 16 ^ 3;
    // 16 = 0001 0000 , 3 = 0000 0011 , 16 ^ 3 = 0001 0011 (or 19)
    printf("x = %d\n", a);
}