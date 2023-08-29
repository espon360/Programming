#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){

	// Declare and initialize string variable
	char character;
	printf("Please enter a single character: ");
	scanf("%c", &character);
    
    // Conditional Statement (you can also use ASCII values)
    // For example if(character >= 65 && letter <= 90) for uppercase
    // or you can use if(character >= 'A'&& letter <= 'Z')
    if(isupper(character)){
        printf("Uppercase");
    }
    else if(islower(character)){
        printf("Lowercase");
    }
    else printf("Other");
    
	return 0;
}
