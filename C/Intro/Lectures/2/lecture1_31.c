
#include<stdio.h>

int main(){
	int x; // declare a variable X
	x = 0; // assignment statement

	int y = 5; // initialize

	x = x+1; // reassign X, 0+1=1. Right side is old assignment and left is new assingment

	printf("%d\n", y); // 5
	y = y+1; // reassign Y to 6=5+1
	printf("%d\n", y); // 6
	y = x+y; // x=1, y=6 from previous assingment

	printf("the value of x is: %d the value of y is: %d.\n", x, y);

	return 0;
}
