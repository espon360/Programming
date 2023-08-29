// CSE 1320 Intermediate Programming
// Linked List Example 3
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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
void addNode(Node **ppHead, int data)
{
	Node *pNode = malloc(1*sizeof(Node));
	pNode->data = data;
	pNode->pNext = *ppHead;
	*ppHead = pNode;
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

// Delete all nodes in linked list
void deleteAllNodes(Node **ppHead)
{
	// Point node to head of the array
	Node *pNode = *ppHead;
	Node *pNextNode;
	while (pNode != NULL) // if there is nothing in the node, don't do code below / recur deletion until you enter the final NULL
	{
		// store next node before deleting node
		pNextNode = pNode->pNext; // so that way when the node is deleted, you will still have the pointer to the next node to delete that one
		// delete the node
		free(pNode); // freeing the data from pNode will simply delete it
		// update node to next node
		pNode = pNextNode; // the pointer that was taken on line 51 will now be used to get the next Node
	}
	// Update the pointer the link to be null
	*ppHead = NULL;
}

int main(void)
{
	Node *pHead = NULL;
	addNode(&pHead, 1);
	addNode(&pHead, 2);
	addNode(&pHead, 3);
	printf("List after adding 1, 2, 3\n");
	printData(pHead);
	deleteAllNodes(&pHead);
	printf("List after deleting all\n");
	printData(pHead);
    return EXIT_SUCCESS;
}
