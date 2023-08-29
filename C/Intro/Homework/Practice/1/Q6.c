#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){

	// Declare and initialize string variable
	char ch;
	printf("Please enter a single character: ");
	scanf("%c", &ch);
    
    // Conditional statements

    if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' 
    || ch == 'u' || ch == 'U'){
    	printf("Vowel");
    }
    else if(ch > 'A' && ch <= 'Z' || ch > 'a' && ch <= 'z'){
    	printf("Consonant");
    }
    else printf("Other");

    return 0;
}
