#include <stdio.h>
int main(){
// Another way to do the greater or less than question

// Initialize and declare variable from user input
	int num1 , num2;
	printf("Enter two integers (seperated by a space): ");
	scanf("%d %d", &num1, &num2);

// Switch statement
	switch(num1 > num2);

	// If True
	case 1: 
		printf("%d is greater than %d", num1, num2);
		break;

	// If False
	case 0:
		printf("%d is greater than %d", num2, num1);
		break;

	}

	return 0;
}
