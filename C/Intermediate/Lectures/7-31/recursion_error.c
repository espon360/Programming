// CSE 1320 Intermediate Programming
// Recursion Example with Error
// Intentionally causes stack overflow
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void fn(void)
{
	// variable x is allocated on the program stack
	// unique address in memory for each time fn() is called
	int x = 0;
	
	// variable count is allocated once
	// the value is remembered between calls to fn()
	// set to zero when the program starts
	static int count = 0;

	// every time fn() is called, the count is increment
	count++;
	
	// print the count and the address of the variable x
	printf("count = %d, &x = %p, &count = %p\n", count, &x, &count);
	// Will continuously print off the addresses of each "x" and the current count (what iteration of the function it's on)
	// Will keep running till you run out of space to allocate

	fn();
}

int main(void)
{
	fn();
	return EXIT_SUCCESS;
}
