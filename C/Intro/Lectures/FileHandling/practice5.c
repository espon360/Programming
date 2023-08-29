// Create program to read integers and get average
#include <stdio.h>
#include <stdlib.h>

void main()
{
    double grades[5], sum = 0;
    int i = 0;

    FILE *gradeFile; // Doesn't have to be fptr, its just a variable pointer
    gradeFile = fopen("numbers.txt", "r"); // Read numbers.txt

    if(gradeFile == NULL) // Check if file does not exist
    {
        printf("Error!\n");
        exit(1);
    }

    while(!feof(gradeFile) && i < 5) // Read gradeFile pointer till end of file
    {
        fscanf(gradeFile, "%lf", &grades[i]);
        sum += grades[i];
        i++;
    }
    double average = sum/5;
    printf("The average quiz grade is: %.2lf", average);

    fclose(gradeFile);
}