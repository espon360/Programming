#include <stdio.h>
#include <math.h>
int main(){
	// Declare and initialize
	double num1, num2, num3;
	printf("Type in 3 numbers seperated by a space:\n");
	scanf("%lf %lf %lf", &num1, &num2, &num3);

	// Conditional Statements
	if(num1 >= num2 && num1 >= num3){
		printf("%lf", num1);
	}
	else if(num2 >= num1 && num2 >= num3){
		printf("%lf", num2);
	}
	else if(num3 >= num1 && num3 >= num2){
		printf("%lf", num3);
	}
	else if(num1 == num2 && num2 == num3){
		printf("All numbers are equal");
	}

	return 0;
}
