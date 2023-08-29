#include <stdio.h>

void calculate_perimeter(double x, double y);
void calculate_area(double x, double y);

void main()
{
    double width, length;
    printf("Please enter the width of a rectangle: ");
    scanf("%lf", &width);

    printf("Now enter its length: ");
    scanf("%lf", &length);

    calculate_perimeter(width, length);
    calculate_area(width, length);
}

void calculate_perimeter(double x, double y)
{
    double p = x*2 + y*2;
    printf("The perimeter of a(n) %.3lf x %.3lf rectangle is: %.3lf\n", x, y, p);
}

void calculate_area(double x, double y)
{
    double a = x * y;
    printf("The area of a(n) %.3lf x %.3lf rectangle is: %.3lf\n", x, y, a);
}
