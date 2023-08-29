#include <stdio.h>
//Simple Calculator
int main(){
	char operation;

	double n1, n2;

// Input operator
	printf("Enter an operator (+, -, *, /): ");
	scanf("%c", &operation);

// Input two numbers
	printf("Enter two numbers seperated by a space: ");
	scanf("%lf %lf", &n1, &n2);

// Switch for calculations
	switch(operation){
		
		case '+':
			printf("%.1lf + %.1lf = %.1lf", n1, n2, n1 + n2);
			break;

		case '-':
			printf("%.1lf - %.1lf = %.1lf", n1, n2, n1 - n2);
			break;

		case '*':
			printf("%.1lf * %.1lf = %.1lf", n1, n2, n1 * n2);
			break;

		case '/':
			printf("%.1lf / %.1lf = %.1lf", n1, n2, n1 / n2);
			break;

		default: printf("Cannot compute based on arithmetic operations available.\n");
	}

	return 0;
}
