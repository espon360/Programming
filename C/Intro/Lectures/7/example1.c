#include <stdio.h>
int main() {
	// Initialize Grade
	double grade;

	// Ask for user input
	printf("Please enter your grade: ");
	scanf("%lf", &grade);

	if(grade >= 70){
		printf("You Passed!\n");
	}
	else
		{printf("You suck!\n");}

	return 0;
}
