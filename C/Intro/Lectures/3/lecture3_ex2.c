#include <stdio.h>

int main(){

	// declare variables
	int num1, num2, result;

	//ask user for two numbers
	printf("Enter the first number: ");
	scanf("%d", &num1);

	printf("Enter the second number: ");
	scanf("%d", &num2);

	//compute sum
	result = num1+num2;

	//print the sum
	printf("The sum of %d and %d is %d.\n", num1, num2, result);

	return 0;
}
