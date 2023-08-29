#include <stdio.h>
int main(){

	// Initialize and declare variable
	double weight, cost;
	printf("Please input the weight of the package: ");
	scanf("%lf", &weight);

	// Conditional statements
	if(weight <= 2)
	{
		cost = 5;
	}
	else if(weight > 2 && weight <= 10)
	{
		cost = 10;
	}
	else
	{
		cost = 15;
	}

	printf("The cost of shipping for %.2lf lbs package is $%.2lf.\n", weight, cost);

	return 0;
}
