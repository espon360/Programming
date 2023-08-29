// CSE 1320 Intermediate Programming
// Strings example 2
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>

/*
// Function to replicate the function of strlen
int strLength(const char str[])
{
    int index = 0;
    while (str[index] != '\0')
        index++;
    return index;
}

// Function to replicate the function of strlen
int strLength(const char *str)
{
    int index = 0;
    while (str[index] != '\0')
        index++;
    return index;
}

// Function to replicate the function of strlen
int strLength(const char *str)
{
    int index = 0;
    while (*(str+(index++)) != '\0') { }
    index --;
    return index;
}

// Function to replicate the function of strlen
int strLength(const char *str)
{
    int index = 0;
    while (*(str+index) != '\0')
        index++;
    return index;
}

*/

// Function to replicate the function of strlen
int strLength(const char *str)
{
    int length = 0;
    while (*(str++) != '\0')
        length++;
    return length;
}

// Function to concatenate strFrom on the end of strTo
// strTo must be sized to hold contents of strTo and strFrom
char* strCat(char *strTo, const char *strFrom)
{
	// save original value of strTo
	char *strToOriginal = strTo;
	// advance strTo pointer to the position of the null in strTo
    while (*strTo != '\0')
    	strTo++;
    // copy all characters in strFrom to strTo
    while (*strFrom != '\0')
    	*(strTo++) = *(strFrom++);
    // append a null to the end of strTo
    *strTo = '\0';
    return strToOriginal;
}

// Function to copy contents of one string to another
// strTo must be sized to hold contents of and strFrom
char* strCpy(char *strTo, const char *strFrom)
{
	// save original value of strTo
	char *strToOriginal = strTo;
	// copy all characters in strFrom to strTo
    while (*strFrom != '\0')
    	*(strTo++) = *(strFrom++);
    // append a null to the end of strTo
    *strTo = '\0';
    return strToOriginal;
}

int main(void)
{
    char str[] = "Hello world";
    char str2[20] = "Hello ";
    char str3[7] = "world!";
    char str4[20];
    printf("sizeof(char) = %d\n", (int)sizeof(char));
    printf("sizeof(str) = %d\n", (int)sizeof(str));    
    for (int i = 0; i < (int)sizeof(str); i++)
    	printf("str[%02d] = '%c' = 0x%02x (ASCII code), &str[%d] = %p\n", i, str[i], str[i], i, &str[i]);
    int length = strLength(str);
    printf("Length ostr2f string \"%s\" is %d\n", str, length);
    printf("str2 = %s\n", str2);
    printf("str3 = %s\n", str3);
    printf("str2 after strCat = %s\n", strCat(str2, str3));
    strCpy(str4, str2);
    printf("str4 after strCpy = %s\n", str4);
    
    return EXIT_SUCCESS;
}
