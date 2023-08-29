// CSE 1320 Intermediate Programming
// Structs file example
// Crowd-sourced solution from class
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHARS_PER_LINE 40
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
    FILE *file = fopen("point_pairs.txt", "r");
    if (file == NULL)
    {
        printf("File could not be opened\n");
        exit(EXIT_FAILURE);
    }
    char buffer[MAX_CHARS_PER_LINE+1];
    char *token;
    char delim[] = ", \t";
    Point *points = malloc(1*sizeof(Point));
    int count = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
#ifdef DEBUG
        printf("Line: %s\n", buffer);
#endif
        token = strtok(buffer, delim);
        if (token != NULL)
        {
#ifdef DEBUG
            printf("Token 1: %s\n", token);
#endif
            points[count].x = atoi(token);
            token = strtok(NULL, delim);
            if (token != NULL)
            {
#ifdef DEBUG
                printf("Token 2: %s\n", token);
#endif
                points[count].y = atoi(token);
                // Grow count and realloc space in array
                count++;
                points = realloc(points, (count+1)*sizeof(Point));
            }
        }
    }
    Point center;
    getCenter(&center, points, count);
    for (int i = 0; i < count; i++)
        printf("Point %d = (%d, %d)\n", i, points[i].x, points[i].y);
    printf("Center of the points = (%d, %d)\n", center.x, center.y);
    free(points);
    fclose(file);
    
    return EXIT_SUCCESS;
}
