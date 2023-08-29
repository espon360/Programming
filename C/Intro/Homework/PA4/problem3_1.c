#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    // Random number generator set 1-100
    srand(time(NULL));
    int r = rand()%100+1; 

    // Take user input for number
    int guess, attempt = 1;

    printf("I'm thinking of a number between 1-100, please take a guess: ");
    scanf("%d", &guess);

    // while loop to test if guess unequal to number
    while(guess != r)
    {
        // Nested switch statement specifying what the guess was in relation to the number
        switch (guess > r)
        {
            case 1:
                printf("That's a lil too big... how about try again? ");
                attempt++;
                scanf("%d", &guess);
                break;
            default:
                printf("That's a lil small isn't it? Let's try again ");
                attempt++;
                scanf("%d", &guess);
        }
    }

    printf("Eh, that'll do. My number was %d, looks like it took you %d attempt(s).\n", r, attempt);

    return 0;
}
