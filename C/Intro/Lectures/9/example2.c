#include <stdio.h>
int main(){
// Another way to do the odd/even question

// Initialize and declare variable from user input
	int num;
	printf("Enter an integer num: ");
	scanf("%d", &num);

// Switch statement for odd and even
	switch(num % 2){

	case 0:
		printf("Even");
		break;

	case 1:
		printf("Odd");
		break;
		// Last break is redundant but just do it as good practice
	}

	return 0;
}
