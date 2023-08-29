#include <stdio.h>
int main()
{
    // constant variable
    const int MSIZE = 2;
    
    // Integer matrix constant variable size (2 x 2)
    // First bracket is the row and second bracket is the column
    int m1[MSIZE][MSIZE], m2[MSIZE][MSIZE];
   
    int sum[MSIZE][MSIZE];
    // Get user input for the m1 matrix
    printf("Enter elements of the first matrix: \n");
    
    // Accessing Rows
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

    // Display inputted values for array
    for(int i = 0; i < MSIZE; i++)
    {
        for(int j = 0; j < MSIZE; j++)
        {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    // Get user input for the m2 matrix
    printf("Enter elements of the second matrix: \n");
    
    // Accessing Rows
    for(int i = 0; i < MSIZE; i++)
    {
        // Accessing Columns
        for(int j = 0; j < MSIZE; j++)
        {
            // displays which row and column you're inputting for
            printf("Enter element for m2[%d][%d]: ", i+1, j+1);
            scanf("%d", &m2[i][j]);
        }   
    }

    // Display inputted values for array
    for(int i = 0; i < MSIZE; i++)
    {
        for(int j = 0; j < MSIZE; j++)
        {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }

    // Get sum for array m1+m2
    for(int i = 0; i < MSIZE; i++)
    {
        for(int j = 0; j < MSIZE; j++)
        {
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }

    // Display sum values for sum[][]
    printf("Here is the sum of the inputted arrays: \n");
    for(int i = 0; i < MSIZE; i++)
    {
        for(int j = 0; j < MSIZE; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }   

    return 0;
}
