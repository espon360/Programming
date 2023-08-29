// CSE 1320 Intermediate Programming
// HW6 Functions
// Parse CSV File with double-quoted fields
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hw6_fns.h"

#define OFS_TO_BUSINESS 3
#define OFS_TO_ADDRESS 2
#define OFS_TO_CONTACT 4

void getBusiness(char strBusiness[], const char strLine[])
{
    char *token;
    char delim[] = ",";
    char *str;
    int skip = 0;
    // Allocate space for local r/w copy of strLine
    str = malloc((strlen(strLine)+1)*sizeof(char));
    if (str != NULL)
    {
    	// Copy strLine to local r/w copy
		strcpy(str, strLine);

		// Get first field
		token = strtok(str, delim);

		// Skip fields and get desired field
		while (skip < OFS_TO_BUSINESS && token != NULL)
		{
			token = strtok(NULL, delim);
			skip++;
		}
		// Copy result to return string
		if (token != NULL)
			strcpy(strBusiness, token);
		else
	    	strcpy(strBusiness, "\0");
		free(str);
    }
    else
	// If entire line is blank
    	strcpy(strBusiness, "\0");
}

void getAddress(char strAddress[], const char strLine[])
{
    char *token;
    char delim[] = ",";
    char *str;
    int skip = 0;
    // Allocate space for local r/w copy of strLine
    str = malloc((strlen(strLine)+1)*sizeof(char));
    if (str != NULL)
    {
    	// Copy strLine to local r/w copy
		strcpy(str, strLine);
		// Get first field
		token = strtok(str, delim);
		// Skip fields and get desired field
		while (skip < OFS_TO_ADDRESS && token != NULL)
		{
			token = strtok(NULL, delim);
			skip++;
		}
		// Copy result to return string
		if (token != NULL)
			strcpy(strAddress, token);
		else
	    	strcpy(strAddress, "\0");
		free(str);
    }
	else
	// If entire line is blank
		strcpy(strAddress, "\0");
}

void getContact(char strContact[], const char strLine[])
{
    char *token;
    char delim[] = ",";
    char *str;
    int skip = 0;
    // Allocate space for local r/w copy of strLine
    str = malloc((strlen(strLine)+1)*sizeof(char));
    if (str != NULL)
    {
    	// Copy strLine to local r/w copy
		strcpy(str, strLine);
		// Get first field
		token = strtok(str, delim);
		// Skip fields and get desired field
		while (skip < OFS_TO_CONTACT && token != NULL)
		{
			token = strtok(NULL, delim);
			skip++;
		}
		// Copy result to return string
		// handle case of empty string
		if (token != NULL)
		{
			if (strcmp(token, ",") == 0)
				strcpy(strContact, "(none)");
			else
				strcpy(strContact, token);
		}
		free(str);
    }
    else
	// If entire line is blank
    	strcpy(strContact, "\0");
}


