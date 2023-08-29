#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
	//Declare and initialize variable
	int number, decide;
	char type[4];
	printf("Please enter a whole number: ");
	scanf("%d", &number);
	decide = number % 2;

	//Conditional
	if(decide == 0){
		strcpy(type, "even");
	}
	else 
		strcpy(type, "odd");

	//Display result
	printf("The number is %s.\n", type);

	return 0;
}
