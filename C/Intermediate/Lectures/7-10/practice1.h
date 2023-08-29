// practice header for minmax.c program
// to include, type as such: #include "practice1.h"
// the "__" is for local header file not in computer OS

// This header file will include a min, max, and sort function

// #ifndef = if not defined
#ifndef _practice1_H_
// If not defined, it will define _practice1_H_ and paste the entire functions below till #endif
// Will publically declare the following functions as prototypes that can be called
/* Doing this makes it so you can include the header and program still runs in case the functions below are locally 
written as well on the c program */
#define _practice1_H_

int min(const int *x, int count);

int max(const int *x, int count);

void sort(const int *x, int count);

#endif 

// The function definitions are going to be written in a practice1.c file (which is named exactly like the header file for clarity)
// When typing 