#include <stdio.h>
#include <string.h>

int main()
{
	// Format as Bdate ==> MON Day, Year

	// Declare variables
	char month[20];
	int day, year;

	// User input for month, then day, then year
	printf("Please enter your birth month: ");
	gets(month);
	printf("Please enter your birth day: ");
	scanf("%d", &day);
	printf("Please enter your birth year: ");
	scanf("%d", &year);

	// Print birthday
	printf("Your birthday is: %s %d %d\n.", month, day, year);

	return 0;
}
