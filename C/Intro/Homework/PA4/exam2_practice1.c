#include <stdio.h>

float average(float, float, float, float, float, float, float);
int main()
{
    float d1, d2, d3, d4, d5, d6, d7, week;
    printf("Please enter the daily temperature for each day of the week seperated by a space: ");
    scanf("%f %f %f %f %f %f %f", &d1, &d2, &d3, &d4, &d5, &d6, &d7);

    week = average(d1, d2, d3, d4, d5, d6, d7);
    printf("The average temperature for the past week is: %.2f degrees", week);

    return 0;
}

float average(float d1, float d2, float d3, float d4, float d5, float d6, float d7)
{
    float avg;
    avg = (d1+d2+d3+d4+d5+d6+d7) / 7;
    return avg;
}
