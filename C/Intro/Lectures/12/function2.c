#include <stdio.h>

void validate(char letter);

int main()
{
    printf("Please enter a capital letter: ");
    scanf("%c", %l);

    validate(l);

    printf("The letter you chose is: ", l);

    return 0;
}

void validate(char letter)
{
        while(letter < A || letter > Z)
        {
        printf("Please print a valid character: ");
        scanf("%c", &l);
        }

    return letter;
}
