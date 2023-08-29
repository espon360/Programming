/*Write a function that takes a character as input and returns true 
if the character is a capital letter and false otherwise.*/

#include <stdio.h>
void main()
{
    char letter;
    printf("Please input a letter: ");
    scanf("%c", &letter);

    switch(letter >= 'A' && letter <= 'Z')
    {
        case 1:
        printf("%c is a capital letter.\n", letter);
        break;

        case 0:
        printf("%c is not a capital letter.\n", letter);
        break;
    }
}