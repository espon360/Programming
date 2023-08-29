#include <stdio.h>
int main(){
	// Declare and initialize variable
	int day;
	printf("Enter a day of the week as a number (ex: 1 = Sun and 7 = Sat): ");
	scanf("%d", &day);

	// Switch statements
	switch(day){
		case 2:
			printf("Monday is a weekday\n");
			break;
		case 3:
			printf("Tuesday is a weekday\n");
			break;
		case 4:
			printf("Wednesday is a weekday\n");
			break;		
		case 5:
			printf("Thursday is a weekday\n");
			break;	
		case 6:
			printf("Friday is a weekday\n");
			break;			
		case 1:
			printf("Sunday is in the weekend\n");
			break;
		case 7:
			printf("Saturday is in the weekend\n");
			break;
		default: printf("Invalid input\n");
	}

	return 0;
}
