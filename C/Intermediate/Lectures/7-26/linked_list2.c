// CSE 1320 Intermediate Programming
// Linked List Example 2
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>

typedef struct _Node
{
	int data;
	struct _Node *pNext;
} Node;

// Given a pointer to a pointer to the head of the linked list (ppHead)
// (ppHead is the address of pHead in main)
// (pHead in main contains the address of the head node in linked list)
// create a new Node (pNode)
// store data value in Node
// connect pNext to previous head (*ppHead)
// update ppNode value to be the address of the new head
// (write the address of the new head to the pHead in main)

void addNode(Node **ppHead, int data) // Pass the address of the Node (so that the Node in main is modified as well)
{
	Node *pNode = malloc(1*sizeof(Node)); // allocate 1 size of struct Node to pNode
	pNode->data = data; // declare data of pNode as data argument passed
	pNode->pNext = *ppHead; // set pointer pNext for pNode to the ppHead (need to dereference since argument passed as pointer to pointer)
	*ppHead = pNode; // ppHead in main will now be pNode
}

// Starting printing data from head to the tail of the linked list
void printData(Node *pHead)
{
	Node *pNode = pHead;
	while(pNode != NULL)
	{
		printf("%d\n", pNode->data);
		pNode = pNode->pNext;
	}
}

int main(void)
{
	Node *pHead = NULL; // original head pointer is NULL
	addNode(&pHead, 1); // pass address of pHead so that pHead now becomes the new data value that was passed as arugment[1]
	addNode(&pHead, 2);
	addNode(&pHead, 3);
	printData(pHead);

	// same as first "linked_list.c" code but is cleaner since you don't have to constantly set pHead Node to new data
    return EXIT_SUCCESS;
}
