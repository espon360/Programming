#include <stdio.h>

void main()
{
    // Get user input for number of students

    // int student
    // int studen
    // int student{}
    int student;
    do
    {
        printf("Please input the number of students in class: ");
        scanf("%d", &student);
    } while(student <= 0);

    float grade[student], sum = 0;
    // Get user input for grades in class and sum
    for(int i = 0; i < student; i++)
    {
        printf("Please enter the grade for student no.%d: ", i+1);
        scanf("%f", &grade[i]);
        sum += grade[i];
    }
    // Calculate average
    float avg = sum / student;

    // Get highest and lowest grade
    float min = grade[0], max = grade[0];
    for(int j = 0; j < student; j++)
    {
        if(min > grade[j])
        {
            min = grade[j];
        }
        if(max < grade[j])
        {
            max = grade[j];
        }
    }

    printf("The class average was %.2f, with the highest being %.2f and lowest being %.2f.\n", avg, max, min);
}
