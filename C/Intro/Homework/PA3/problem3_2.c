#include <stdio.h>
int main(){
// Initialize and declare
	int num1, num2;
	printf("Please enter two integers seperated by a space: ");
	scanf("%d %d", &num1, &num2);
    
// Conditinal if statement
	if(0 == num1 % num2){
		printf("The first number is divisible by the second number\n");
	}
	else printf("The first number is not divisible by the second number\n");

	return 0;
}
