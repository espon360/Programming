#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){

	// Initialize and declare
	double number;
	printf("Please enter a number: ");
	scanf("%lf", &number);
	char type[20];

	// Conditional statements
	if(number > 0){
		strcpy(type, "positive");
	}
	else if(number == 0){
		strcpy(type, "zero");
	}
	else
		strcpy(type, "negative");

	//Display result
	printf("%lf is %s.\n", number, type);

	return 0;
}
