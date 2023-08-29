#include <stdio.h>
#include <stdlib.h>

void takeWord()
{
    char warden[20];

    FILE *answer;
    answer = fopen("input.txt", "w"); 

    if(answer == NULL)
    {
        printf("Error! File not found.\n");
        exit(1);
    }

    fgets(warden, sizeof(warden), stdin);
    fprintf(answer, "%s\n", warden);

    system("cls");
}
// C:\Users\duong\Desktop\Classes\Programming\Lectures\FileHandling