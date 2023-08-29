// CSE 1320 Intermediate Programming
// Linked List Example 4
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
void printHeadToEnd(Node **ppHead)
{
	Node *pNode = *ppHead;
	while(pNode != NULL)
	{
		printf("%d\n", pNode->data);
		pNode = pNode->pNext;
	}
}

// Starting printing data from tail to the head of the linked list
void printEndToHead(Node *pNode)
{
	if (pNode != NULL)
	{
		printEndToHead(pNode->pNext);
		if (pNode != NULL)
			printf("%d\n", pNode->data);
	}
}

// Delete node with the first instance of the data value
// return true is data value was found, false else
bool deleteNode(Node **ppHead, int data)
{
	// pointer for the current node
    Node* pCurrentNode = *ppHead;

    // pointer to the previous node
    // (starting at the head, there is no previous node in the linked list)
    Node* pPreviousNode = NULL;
    
    // variable to tell if we have found the data value yet
    bool found = false;
    
    // enter a loop until:
    // - find the matching data value
    // - reached the end of the linked list
    // using demorgan's theorem #1
    // stay in loop while:
    // - matching data value not found
    // - not reached the end of the linked list
    while (!found && pCurrentNode != NULL)
    {
    	found = pCurrentNode->data == data;
    	if (!found)
    	{
    		pPreviousNode = pCurrentNode;
    		pCurrentNode = pCurrentNode->pNext;
    	}
    }
    // if the data value was found, fix links and delete node
    if (found)
    {
    	// case where we are deleting the head
    	if (pPreviousNode == NULL)
    		*ppHead = pCurrentNode->pNext;
    	// case where deleting in the middle of the linked list
    	else
    		pPreviousNode->pNext = pCurrentNode->pNext;
        // free the node being deleted
    	free(pCurrentNode);
    }
    return found;
}

// Delete all nodes in linked list
void deleteAllNodes(Node **ppHead)
{
	// Point node to head of the array
	Node *pNode = *ppHead;
	Node *pNextNode;
	while (pNode != NULL)
	{
		// store next node before deleting node
		pNextNode = pNode->pNext;
		// delete the node
		free(pNode);
		// update node to next node
		pNode = pNextNode;
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
	printHeadToEnd(&pHead);

	printf("Print from end to head\n");
	printEndToHead(pHead);
	
	deleteNode(&pHead, 3);
	printf("List after deleted 3\n");
	printHeadToEnd(&pHead);
	
	addNode(&pHead, 4);
	printf("List after add 4\n");
	printHeadToEnd(&pHead);

	deleteNode(&pHead, 2);
	printf("List after deleted 2\n");
	printHeadToEnd(&pHead);

	deleteAllNodes(&pHead);
	printf("List after deleting all\n");
	printHeadToEnd(&pHead);
	
    return EXIT_SUCCESS;
}
