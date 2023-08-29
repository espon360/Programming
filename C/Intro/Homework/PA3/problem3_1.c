#include <stdio.h>
int main(){
	// Initialize and declare
	int num1, num2;
	printf("Please enter two integers seperated by a space: ");
	scanf("%d %d", num1, num2);

	// Switch statement
	switch (num1 % num2){

	case 0:
		printf("The first number is divisible by the second number.\n");
		break;
	default:
		printf("The first number is not divisible by the second number.\n");
		break;
}
	return 0;
}
