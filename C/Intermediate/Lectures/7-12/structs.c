// CSE 1320 Intermediate Programming
// Structs example (Structures with static memory allocation)
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>

#define COUNT 3

typedef struct _Point
{
    int x;
    int y;
} Point;

// center is pointer to where to store the calculated center point
// points[] array of points whose value is sent to the function
// count is the number of points

// Point *center is dereferencing address of center
void getCenter(Point *center, Point points[], int count)
{
    int sumX = 0;
    int sumY = 0;
    int meanX, meanY;
    for (int i = 0; i < count; i++)
    {
        sumX += points[i].x;
        sumY += points[i].y;
    }
    meanX = sumX / count;
    meanY = sumY / count;

    // Pointer to a structure gets dereferenced by '->'
    // Is dereferencing x / y value of center 
    center->x = meanX;
    center->y = meanY;
}

int main(void)
{
    // examples of declaring and initializing struct instances
    // Initializing in order of declarations on line 10-14
    struct _Point pt1;
    pt1.x = 10;
    pt1.y = 20;
    Point pt2;
    pt2.x = 20;
    pt2.y = 30;
    Point pt3 = {0, 0}; // first value automatically assigned to x and second automatically assigned to y (useful for structures with low number of fields)
    Point pt4 = {.x=0, .y=0}; // same as pt3 but only assigns x and y fields if there are more fields (partial initialize)
    
    // find center of a set of points
    Point center;
    Point points[COUNT];
    points[0].x = -10;
    points[0].y = 0;
    points[1].x = 10;
    points[1].y = 0;
    points[2].x = 0;
    points[2].y = 15;

    // You're passing the address of center since it'll get dereferenced and value changed at address
    getCenter(&center, points, COUNT);
    for (int i = 0; i < COUNT; i++)
        printf("Point %d = (%d, %d)\n", i, points[i].x, points[i].y);
    printf("Center of the points = (%d, %d)\n", center.x, center.y);
    return EXIT_SUCCESS;
}

