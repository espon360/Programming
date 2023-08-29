#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int start, result, choice;
FILE *answer, *blank, *hs, *h1, *h2, *h3, *h4, *h5, *he;

// Location of file: C:\Users\duong\Desktop\Classes\Programming\Hangman

int game();
void nextText();
void takeWord();
void testOpen(FILE *fptr);
void printHangman(FILE *fptr);
void printBlank();
void main()
{
    system("cls");
    // Boot up game
    printf("Greetings traveler, would you like to play a game?\n");
    printf("(Enter 1 for Yes / 0 for No)\n");
    scanf("%d", &start);
    // Invalid responses
    while(start != 0 && start != 1)
    {
        printf("I'm sorry, I didn't understand that, please enter a response.\n");
        printf("(Enter 1 for Yes / 0 for No)\n");
        scanf("%d", &start);
    }
    if(start == 0)
    {
        printf("Very well, thank you for your time. Good bye.\n");
        exit(1);
    }
    system("cls");
    result = 1;
    while(result == 1)
    {
        result = game();
    }
}

int game()
{
    // Open hangman art files
    hs = fopen("hangman_start.txt", "r");
    h1 = fopen("hangman_1.txt", "r");
    h2 = fopen("hangman_2.txt", "r");
    h3 = fopen("hangman_3.txt", "r");
    h4 = fopen("hangman_4.txt", "r");
    h5 = fopen("hangman_5.txt", "r");
    he = fopen("hangman_end.txt", "r");

    if(hs == NULL || h1 == NULL || h2 == NULL || h3 == NULL || h4 == NULL || h5 == NULL || he == NULL)
    {
        printf("ERROR!!! File not found.");
        exit(1); // similar to return 0
    }

    // Check if two players are ready
    printf("This game requires two people to play. Please assign someone as the\n");
    printf("warden and the other as a player.\n");
    do
    {
        printf("When you're ready, please enter a '1'\n");
        scanf("%d", &start);
    } while(start != 1);

    system("cls");

    // Game start w/ narrator
    printHangman(hs);
    printf("\n");
    printf("Well well well, looks like you're in quite the pickle huh?\n");
    printf("I mean capital punishment? Not your luckiest day.\n");
    printf("But you're in luck, seems like the warden's offering you a lifeline.\n");
    nextText();
    
    printf("Hehe, line. Get it?\n");
    printf("Anyways, they said if you can best them in a game of hangman, you're off the hook.\n");
    printf("Man, what a sadistic fellow.\n");
    nextText();

    printf("Either way, it's you're only option. Nod if you understand me.\n");
    printf("(Enter a '1' to nod // '0' to shake your head)\n");
    scanf("%d", &choice);

    while(choice != 1)
    {
        if(choice == 0)
        {
            printf("Are you trying to piss me off? C'mon, give me a nod.\n");
            printf("(Enter a '1' to nod // '0' to shake your head)\n");    
            scanf("%d", &choice);    
        }
        else
        {
            printf("Uhh not sure what kind of head motion that was but let's try again...\n");
            printf("(Enter a '1' to nod // '0' to shake your head)\n");    
            scanf("%d", &choice);    
        }
    }
    system("cls");
    printf("Alright, glad to hear it.\n");
    printf("Now buzz off while I go talk to the warden.\n");
    nextText();

    printf("Warden, if you would, please enter your word:\n");
    printf("(Please enter a word / phrase with 20 characters or less)\n");
    takeWord();
    char hint[100];
    printf("If you're feeling nice, you can include a hint as well for the lil guy: \n");
    fflush(stdin);
    fgets(hint, 20, stdin);

    printf("Sweet, you can call the stooge back now.\n");
    nextText();

    printHangman(hs);
    printf("\nWord: ");
    printBlank();
    printf("\nAlright then, how about we start off with something easy, perhaps a vowel?\n");
    printf("Who am I kidding? Go nuts, no need to listen to that disembodied voice\n");
    printf("inside your head (aka me).\n");

    // Game Variables
    blank = fopen("output.txt", "r");
    answer = fopen("input.txt", "r");
    char guess, fill[20], check[20];
    int m = 0, j = 0;
    fgets(fill, 20, blank);
    fgets(check, 20, answer);

    printf("(Quick disclaimer: Capital letters and spaces do count so don't forget to input those)");
    printf("\n(Hit enter once when you're ready, the warden will send you an arrow to show you they're ready)\n");

    while(strncmp(check, fill, strlen(check)) != 0)
    {
        
        fflush(stdin);
        guess = fgetc(stdin);

        for(int i = 0; i <= 20; i++)
        {
            if(check[i] == guess)
            {
                fill[i] = check[i];
                j++;
            }
        }

        // If no letters are replaced, it means guess was wrong
        if(j == 0)
        {
            m++;
            // Print mistake messages for new errors
            switch(m)
            {
                case 0:
                break;

                case 1:
                system("cls");
                printHangman(h1);
                break;

                case 2:
                system("cls");
                printHangman(h2);
                break;

                case 3:
                system("cls");
                printHangman(h3);
                break;

                case 4:
                system("cls");
                printHangman(h4);
                break;

                case 5:
                system("cls");
                printHangman(h5);
                break;

                case 6:
                system("cls");
                printHangman(he);
                printf("\nThe word was: %s\n", check);
                nextText();
                exit(1);
            }
        }
        printf("--> %s\n", fill);
        printf("Hint: %s\n", hint);
        j = 0;
    }

    fclose(hs);
    fclose(h1);
    fclose(h2);
    fclose(h3);
    fclose(h4);
    fclose(h5);
    fclose(he);
    fclose(blank);
    fclose(answer);

    printf("\nWell would you look at that, looks like you did it!\n");
    printf("As the warden said, a promise is a promise.\n");
    printf("You're free to go now. :)\n");
    printf("Buutttt... if you ever wanna play again, you could always just say so:\n");

    printf("(Enter a '1' to play again or any other number to exit the game.)\n");
    scanf("%d", &result);
    if(result == 1)
    {
        return result;
    }
    else
    {
        system("cls");
        printf("Thank you for playing!\n");
        nextText();
        exit(1);
    }
}

// Function to advance dialogue
void nextText()
{
    do
    {
    printf("(Press '1' enter to continue)\n");
    scanf("%d", &choice);
    } while(choice != 1);
    
    system("cls");
}

// Function to take word from Warden player
void takeWord()
{
    char warden[20];

    answer = fopen("input.txt", "w");

    testOpen(answer);

    // Take user input
    fflush(stdin);
    fgets(warden, 20, stdin);
    while(strlen(warden) > 20)
    {
        printf("That's too long, try something else.\n");
        scanf("%s", &warden);
    }

    fprintf(answer, "%s", warden);
    rewind(answer);
    fclose(answer);
    system("cls");
}

// Display image of hangman folder selected
void printHangman(FILE *fptr)
{
    while(!feof(fptr))
    {
        printf("%c", fgetc(fptr));
    }
    rewind(fptr);
}

// Print blank spaces equal to characters in input.txt
void printBlank()
{
    answer = fopen("input.txt", "r");
    blank = fopen("output.txt", "w+");

    testOpen(answer);
    testOpen(blank);

    char c = fgetc(answer), u = '-';

    while(!feof(answer))
    {
        if(c == ' ')
        {
            printf("  ");
            fprintf(blank, "%c ", c);
        }
        else if(c != '\n')
        {
            printf("-");
            fprintf(blank, "%c", u);
        }
        c = fgetc(answer);
    }
    fclose(answer);
    fclose(blank);
}

// If statement to check if file opened
void testOpen(FILE *fptr)
{
    if(fptr == NULL)
    {
        printf("ERROR!!! File not found.");
        exit(1); // similar to return 0
    }
}