// CSE 1320 Intermediate Programming
// Binary search tree 2 example
// Includes trivial hacked debug print of the tree (not part of the class)
// Requires C99 (use -std=c99 option or works by default with GCC)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct _BNode
{
	int data;
	struct _BNode *pLeft;
	struct _BNode *pRight;
} BNode;

BNode * addNode(int data)
{
	BNode* pNode = malloc(sizeof(BNode));
	pNode->data = data;
	pNode->pLeft = NULL;
	pNode->pRight = NULL;
	return pNode;
}

void insertNode(BNode *pNode, int data)
{
	if (pNode != NULL)
	{
		// left
		if (data < pNode->data)
		{
			if (pNode->pLeft == NULL)
			{
				pNode->pLeft = addNode(data);
			}
			else
			{
				insertNode(pNode->pLeft, data);
			}
		}
		// right
		else
		{
			if (pNode->pRight == NULL)
			{
				pNode->pRight = addNode(data);
			}
			else
			{
				insertNode(pNode->pRight, data);
			}
		}
	}
}

void deleteAllNodes(BNode *pNode)
{
	if (pNode != NULL)
	{
		deleteAllNodes(pNode->pLeft);
		deleteAllNodes(pNode->pRight);
		free(pNode);
	}
}

void printDataInOrder(BNode *pNode)
{
	if (pNode != NULL)
	{
		printDataInOrder(pNode->pLeft);
		printf("%d\n", pNode->data);
		printDataInOrder(pNode->pRight);
	}
}

void printDataPreOrder(BNode *pNode)
{
	if (pNode != NULL)
	{
		printf("%d\n", pNode->data);
		printDataPreOrder(pNode->pLeft);
		printDataPreOrder(pNode->pRight);
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

// removing pesky test global variables
typedef struct _TD
{
	int value[10];
	int depth[10];
	int count;
	int level;
} TD;

// Not art of class, just used for visualization in class (lines 108 - 146)
void buildTreeDatabase(BNode *pNode, TD *pTD)
{
	if (pNode != NULL)
	{
		pTD->level++;
		buildTreeDatabase(pNode->pLeft, pTD);
		pTD->value[pTD->count] = pNode->data;
		pTD->depth[pTD->count] = pTD->level;
		pTD->count++;
		buildTreeDatabase(pNode->pRight, pTD);
		pTD->level--;
	}
}

void printTree(BNode *pRoot)
{
	char data[10][10];
	int i, j;
	TD treeData;
	if (pRoot != NULL)
	{
		treeData.count = 0;
		treeData.level = -1;
		buildTreeDatabase(pRoot, &treeData);
		for (i = 0; i < 10; i++)
			for (j = 0; j < 10; j++)
				data[i][j] = ' ';
		for (i = 0; i < treeData.count; i++)
			data[treeData.depth[i]][i] = '0' + treeData.value[i];
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				printf("%c ", data[i][j]);
			}
			printf("\n");
		}
	}
}

int main(void)
{
	BNode *pRoot = NULL;
#ifdef PERFECT_TREE
	pRoot = addNode(4);
	insertNode(pRoot, 2);
	insertNode(pRoot, 1);
	insertNode(pRoot, 3);
	insertNode(pRoot, 6);
	insertNode(pRoot, 5);
	insertNode(pRoot, 7);
#endif
#ifndef PERFECT_TREE
	pRoot = addNode(4);
	insertNode(pRoot, 2);
	insertNode(pRoot, 3);
	insertNode(pRoot, 0);
	insertNode(pRoot, 5);
	insertNode(pRoot, 6);
	insertNode(pRoot, 7);
#endif
	
	printf("In-order transversal\n");
	printDataInOrder(pRoot);
	printf("Pre-order transversal\n");
	printDataPreOrder(pRoot);
	printf("Post-order transversal\n");
	printDataPostOrder(pRoot);
	printf("Tree diagram\n");
	printTree(pRoot);
	deleteAllNodes(pRoot);

    return EXIT_SUCCESS;
}

