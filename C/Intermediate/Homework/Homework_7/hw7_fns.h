// CSE 1320 Intermediate Programming
// HW6 Functions: Parse CSV File with double-quoted fields
// HW7 Functions: [TBD]
// Requires C99 (use -std=c99 option or works by default with GCC)

#ifndef _HW7_FNS_
#define _HW7_FNS_

/* -------------------------------------------------------------------------- */
/*                        DECLARATIONS FROM HOMEWORK 7                        */
/* -------------------------------------------------------------------------- */

int existedInArray(char **b, int count, char *check);  // logically similar to findValueInArray
void addValueToArray(int **x, int *count, int index, int value);
void deleteValueFromArray(int **x, int *count, int value);
int countValueInArray(int x[], int count, int value);
int findValueInArray(int x[], int count, int value);

/* -------------------------------------------------------------------------- */
/*                        DECLARATIONS FROM HOMEWORK 6                        */
/* -------------------------------------------------------------------------- */

void getBusiness(char strBusiness[], const char strLine[]);
void getAddress(char strAddress[], const char strLine[]);
void getContact(char strContact[], const char strLine[]);

#endif

