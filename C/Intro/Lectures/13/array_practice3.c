#include <stdio.h>
#define MSIZE 2

void record(int a[MSIZE][MSIZE]);
void display(int a[MSIZE][MSIZE]);
void main()
{
    // First bracket is the row and second bracket is the column
    int m1[MSIZE][MSIZE], m2[MSIZE][MSIZE];
   
    int sum[MSIZE][MSIZE];
    // Get user input for the m1 matrix
    printf("Enter elements of the first matrix: \n");
    
    // Function for taking user input for array
    void record(m1[MSIZE][MSIZE]);

    // Function for displaying array
    void display(m1[MSIZE][MSIZE]);

}

void record(int a[MSIZE][MSIZE])
{
    for(int i = 0; i < MSIZE; i++)
    {
        // Accessing Columns
        for(int j = 0; j < MSIZE; j++)
        {
            // displays which row and column you're inputting for
            printf("Enter element for m1[%d][%d]: ", i+1, j+1);
            scanf("%d", &m1[i][j]);
        }   
    }
}

void display(int a[MSIZE][MSIZE])
{
    for(int i = 0; i < MSIZE; i++)
    {
        for(int j = 0; j < MSIZE; j++)
        {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}
