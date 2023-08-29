// CSE 1320 Intermediate Programming
// Linked List Example 1
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>

typedef struct _Node
{
	int data;
	struct _Node *pNext; // Initializing Node *pNext
} Node;

// Given a pointer to the head of the linked list (pHead)
// (pHead is the address in memory of the current head)
// create a new Node (pNode)
// store data value in Node
// connect pNext to previous head (pHead)
// return the new head (pNode)
// (return value of the new head's address in memory)

Node * addNode(Node *pHead, int data) // returning * of new head
{
	Node *pNode = malloc(1*sizeof(Node)); // allocate 1 size of node for pNode
	pNode->data = data; // set pNode structure's data equal to argument data passed
	pNode->pNext = pHead; // dereference pNext in pNode and set it to the old pHead (so pHead now points to the pNode that was just added)
	return pNode;
}

// Starting printing data from head to the tail of the linked list
void printData(Node *pHead)
{
	Node *pNode = pHead; // sets pNode to first node
	while(pNode != NULL)
	{
		printf("%d\n", pNode->data);
		pNode = pNode->pNext; // sets pNode to next node
	}
}

int main(void)
{
	Node *pHead = NULL; // set pointer to have null data to start
	pHead = addNode(pHead, 1); // add 1 to data of new node than replace pHead pointer to point to the 1
	pHead = addNode(pHead, 2); // add 2 to data of new node before Node with 1 than replace pHead pointer to point to the 2
	pHead = addNode(pHead, 3); // add 3 to data of new node before Node with 2 than replace pHead pointer to point to the 3
	printData(pHead);
	// Outputs 3\n2\n1\n or 3 2 1

	// Order goes from right to left

    return EXIT_SUCCESS;
}
