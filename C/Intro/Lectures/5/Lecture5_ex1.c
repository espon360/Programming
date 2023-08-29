#include <stdio.h>
#include <string.h>

int main()
{

	// declare and assign
	char firstName, lastName, fullName;
		fullname = firstName + lastName;

	// Name input from user
		printf("Enter your first name: ");
		gets(firstName);
		printf("Enter your last name: ");
		gets(lastName);

	// Print full name
		printf("Your full name is: %s\n.", fullName);

	return 0;
}
