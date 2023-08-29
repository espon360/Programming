// CSE 1320 Intermediate Programming
// Binary search tree example
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _BNode
{
    int data;
    struct _BNode *pLeft; // point left side of tree
    struct _BNode *pRight; // point right side of tree
} BNode;

BNode * addNode(int data)
{
    BNode *pNode = malloc(1*sizeof(BNode)); // allocate 1 size of BNode
    pNode->data = data; // set data for the BNode equal to data argument
    pNode->pLeft = NULL; // make left and right side or node NULL
    pNode->pRight = NULL;
    return pNode; // main function will call as BNode *"node name" = addNode("argument value");
}

void insertNode(BNode *pNode, int data)
{
	if (pNode != NULL)
	{
		// left (<)
		if (data < pNode->data)
		{
			if (pNode->pLeft == NULL)
				pNode->pLeft = addNode(data);
			else
				insertNode(pNode->pLeft, data); // will keep recurring if the left node is not empty till you reach the lowest depth
		}
		// right (>=)
		else
		{
			if (pNode->pRight == NULL)
				pNode->pRight = addNode(data);
			else
				insertNode(pNode->pRight, data); // will keep recurring if the left node is not empty till you reach the lowest depth		
		}
	}
}

void printDataInOrder(BNode *pNode)
{
    if (pNode != NULL)
    {
    	printDataInOrder(pNode->pLeft); // recur till you reach furthest left then moves onto the level above
    	printf("%d\n", pNode->data);
    	printDataInOrder(pNode->pRight); // print right side after reaching furthest left depth
    }
}

void printDataPreOrder(BNode *pNode)
{
    if (pNode != NULL)
    {
    	printf("%d\n", pNode->data); // print root first
    	printDataPreOrder(pNode->pLeft); // then keeps going down left side and print each node as it does
    	printDataPreOrder(pNode->pRight); // prints right side once reached left most then moves to right side of tree
    }
}

void printDataPostOrder(BNode *pNode)
{
    if (pNode != NULL)
    {
    	printDataPostOrder(pNode->pLeft);
    	printDataPostOrder(pNode->pRight);
    	printf("%d\n", pNode->data);
    }
}

void deleteAllNodes(BNode *pNode)
{
    if (pNode != NULL)
    {
    	deleteAllNodes(pNode->pLeft); // recur all the way to the left before freeing node and moving up level
    	deleteAllNodes(pNode->pRight); // recurs to the right then frees node and moves back up level
    	free(pNode);
    }
}

int main(void)
{
	// Define root of the binary search tree
	BNode *pRoot = addNode(4);
	// Add nodes to tree
	insertNode(pRoot, 2);
	insertNode(pRoot, 6);
	insertNode(pRoot, 1);
	insertNode(pRoot, 3);
	insertNode(pRoot, 5);
	insertNode(pRoot, 7);
	printf("In-order transversal of the tree (print in tree order)\n");
	printDataInOrder(pRoot);
	printf("Pre-order transversal of the tree\n");
	printDataPreOrder(pRoot);
	printf("Post-order transversal of the tree (same as delete order)\n");
	printDataPostOrder(pRoot);
	deleteAllNodes(pRoot);
    return EXIT_SUCCESS;
}

