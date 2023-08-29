// CSE 1320 Intermediate Programming
// HW6 Functions: Parse CSV File with double-quoted fields
// HW7 Functions: [TBD]
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hw7_fns.h"

/* -------------------------------------------------------------------------- */
/*                         DEFINITIONS FOR HOMEWORK 7                         */
/* -------------------------------------------------------------------------- */

int existedInArray(char **b, int count, char *check)
{
	int i;
	for (i = 0; i < count; i++)
	{
		if (strcmp(b[i], check) == 0)
			return 1;
	}
	return 0;
}

void addValueToArray(int **x, int *count, int index, int value)
{
	int *data;
	// Add value if in range of the current count or adding one to the count
	if (index < ((*count)+1))
	{
		// Get address of the array
		data = *x;
		// Increment count
		(*count) ++;
		// Malloc or realloc depending on the count
		if (data == NULL)
			data = malloc(1*sizeof(int));
		else
			data = realloc(data, (*count)*sizeof(int));
		// Move data down in array if index is not at the end of the array
		for (int i = *count - 1; i > index; i--)
			data[i] = data[i-1];
		// Copy value into array
		data[index] = value;
		// Update address of the array so the C program knows where the array is at
		// as realloc may have move the position of the array when it was resized
		*x = data;
	}
}

void deleteValueFromArray(int **x, int *count, int value)
{
	int *data;
	int i, j;
	// Get address of the array
	data = *x;
	// Search for value (equivalent to findValueInArray)
	for (i = 0; i < *count; i++)
	{
		// If we did find the value
		if (data[i] == value)
		{
			// Move data up in array
			for (j = i; j < *count - 1; j++)
				data[j] = data[j+1];
			// Decrement count
			(*count) --;
			// Malloc or realloc depending on the count
			if (*count == 0)
				data = NULL;
			else
				data = realloc(data, (*count)*sizeof(int));
			// Update address of the array so the C program knows where the array is at
			// as realloc may have move the position of the array when it was resized
			*x = data;
			// Exit loop
			break;
		}
	}
}

int countValueInArray(int x[], int count, int value)
{
	int result = 0;
	for (int i = 0; i < count; i++)
	{
		if (x[i] == value)
			result ++;
	}
	return result;
}

int findValueInArray(int x[], int count, int value)
{
	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (x[i] == value)
		{
			index = i;
			break;
		}
	}
	return index;
}

/* -------------------------------------------------------------------------- */
/*                         DEFINITIONS FROM HOMEWORK 6                        */
/* -------------------------------------------------------------------------- */

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
#ifdef DEBUG
		printf("Line: %s\n", str);
#endif
		// Get first field
		token = strtok(str, delim);
#ifdef DEBUG
		printf("Token: %s\n", token);
#endif
		// Skip fields and get desired field
		while (skip < OFS_TO_BUSINESS && token != NULL)
		{
			token = strtok(NULL, delim);
#ifdef DEBUG
			printf("Token: %s\n", token);
#endif
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
    	strcpy(strContact, "\0");
}


