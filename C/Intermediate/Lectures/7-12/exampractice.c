#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// gcc exampractice.c

typedef struct _student
{
    char name[50];
    unsigned char age;
    float grade;
} student;

void main(int argc, char* argv[])
{
    student *no;
    no = malloc(1*sizeof(student));

    printf("Please enter the number of students you are inputting: ");
    int count;
    fscanf(stdin, "%d", &count);

    for(int i = 0; i < count; i++)
    {
        printf("\nPlease enter the name of the student[%d]: ", i+1);
        fscanf(stdin, "%s", no[i].name);

        printf("Please enter the age of the student[%d]: ", i+1);
        fscanf(stdin, "%d", &no[i].age);

        printf("Please enter the student[%d]'s grade: ", i+1);
        fscanf(stdin, "%f", &no[i].grade);

        no = realloc(no, (i+2)*sizeof(student));

        #ifdef DEBUG
        printf("i = %d\n", i);
        #endif
    }

    char select;
    printf("\nPlease enter the student you wish to look up: ");
    fscanf(stdin, "%u", &select);

    printf("Name: %s\n", no[select-1].name);
    printf("Age: %d\n", no[select-1].age);
    printf("Grade: %.2f\n", no[select-1].grade);
}