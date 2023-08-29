#include <stdio.h>

void main()
{
    // Count number of odd and even numbers in array
    int numbers[10], even = 0, odd = 0;

    // Get user input
    printf("Please enter 10 numbers: ");

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // increment even and odd by testing odd or even
    for(int i = 0; i < 10; i++)
    {
        switch(numbers[i]%2 == 0)
        {
            case 1:
            even++;
            break;

            case 0:
            odd++;
            break;
        }
    }

    printf("There are %d even number(s) and %d odd number(s)", even, odd);
}
