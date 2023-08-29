#include <stdio.h>
int main(){

	double grade;
	scanf("%lf", &grade);
	char letter;
	if(grade >= 90){
		letter = 'A';
	}
	else if(grade >= 80){
		letter = 'B';
	}
	else if(grade < 80){
		letter = 'C';
	}
	else letter = 'F';
	
	printf("%c", letter);

	return 0;
}
