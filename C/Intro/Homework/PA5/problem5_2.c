#include <stdio.h>

void square(int x);
void main()
{
    int n;
    do
    {
        printf("Please enter a positive number: ");
        scanf("%d", &n);
    } while (n <= 0);
    
    printf("Here is a %d x %d square.\n", n, n);
    square(n);
}

void square(int x)
{
    for(int i = 1; i <= x; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}