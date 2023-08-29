// CSE 1320 Intermediate Programming
// Recursion example over 10x10 matrix of chars
// Flood fill with 4-way or 8-way fill
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>

void print(char data[10][10])
{
	int r, c;
	for (r = 0; r < 10; r++)
	{
		for (c = 0; c < 10; c++)
		{
			printf("%c ", data[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

void flood(char data[10][10], int row, int col, char letter)
{
	char oldLetter = data[row][col];
	data[row][col] = letter;
	
	// debug info
#ifdef DEBUG
	static int depth = 0;
	static int count = 0;
	depth++;
	count++;
	printf("%d [%d, %d] %d\n", count, row, col, depth);
#endif
	
	// up
	if (row > 0)
		if (data[row-1][col] == oldLetter)
			flood(data, row-1, col, letter);

	// down
	if (row < 9)
		if (data[row+1][col] == oldLetter)
			flood(data, row+1, col, letter);

	// left
	if (col > 0)
		if (data[row][col-1] == oldLetter)
			flood(data, row, col-1, letter);

	// right
	if (col < 9)
		if (data[row][col+1] == oldLetter)
			flood(data, row, col+1, letter);
	
#ifdef EIGHT
	// up-left
	if (row > 0 && col > 0)
		if (data[row-1][col-1] == oldLetter)
			flood(data, row-1, col-1, letter);

	// up-right
	if (row > 0 && col < 9)
		if (data[row-1][col+1] == oldLetter)
			flood(data, row-1, col+1, letter);
	
	// down-left
	if (row < 9 && col > 0)
		if (data[row+1][col-1] == oldLetter)
			flood(data, row+1, col-1, letter);

	// down-right
	if (row < 9 && col < 9)
		if (data[row+1][col+1] == oldLetter)
			flood(data, row+1, col+1, letter);
#endif

#ifdef DEBUG
	depth--;
#endif
}

int main(void)
{
	char data[10][10] =
	{
		{'.', '.', '*', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '*', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '*', '*', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '*', '*', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '*', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '*', '*', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '*', '*', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '*', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '*', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
	};
	printf("Matrix before flood fill\n");
	print(data);
	flood(data, 2, 2, 'X');
	flood(data, 8, 8, '%');
	flood(data, 1, 1, '+');
	printf("Matrix after flood fill\n");
	print(data);
    return EXIT_SUCCESS;
}
