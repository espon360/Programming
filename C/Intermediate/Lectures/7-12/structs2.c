// CSE 1320 Intermediate Programming
// Structs 2 example (Structures with dynamic memory allocation)
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>

typedef struct _Point
{
    int x;
    int y;
} Point;

// center is pointer to where to store the calculated center point
// points[] array of points whose value is sent to the function
// count is the number of points
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
    center->x = meanX;
    center->y = meanY;
}

int main(void)
{
    Point center;
    Point *points;
    int count;
    int i;
    // note: scanf can be a dangerous function to use in some cases
    printf("Enter the number of points: ");
    scanf("%d", &count);
    points = malloc(count*sizeof(Point));
    if (points == NULL)
    {
        printf("Memory not allocated\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < count; i++)
    {
        // &points[i].x = address of points at i position for x
        printf("x[%d] = ", i);
        scanf("%d", &points[i].x);
        printf("y[%d] = ", i);
        scanf("%d", &points[i].y);
    }
    getCenter(&center, points, count);
    for (i = 0; i < count; i++)
        printf("Point %d = (%d, %d)\n", i, points[i].x, points[i].y);
    printf("Center of the points = (%d, %d)\n", center.x, center.y);

    // Make sure you do this
    free(points);
    return EXIT_SUCCESS;
}

