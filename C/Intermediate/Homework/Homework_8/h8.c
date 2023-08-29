/*Write a function, void addNodeAtHead(Node** head, int value), that accepts a
pointer to the head node and a value to insert at the head of the linked list. 

Write a function, void countNodes(Node** head), that accepts a pointer to the
head node and returns the number of nodes in the linked list. 

Write a function, void countValue(Node** head, int value), that accepts a pointer
to the head node and a value to find (value). The function should return the
number of instances of the value within the linked list. 
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define count 3

typedef struct _Node
{
    int data;
    struct _Node *pNext;
} Node;

void addNodeAtHead(Node** pHead, int value);
void countNodes(Node** pHead);
void countValue(Node** pHead, int value);
void printData(Node** pHead);

int main(void)
{
    Node *pHead = NULL;
    int d;

    for(int i = 0; i < count; i++)
    {
        printf("Please enter item no.%d: ", i+1);
        fscanf(stdin, "%d", &d);
        addNodeAtHead(&pHead, d);
    }

    printData(&pHead);
    countNodes(&pHead);

    int check;
    printf("Please enter the number you wish to look up: ");
    fscanf(stdin, "%d", &check);
    countValue(&pHead, check);
}

void printData(Node** pHead)
{
    Node *pNode = *pHead;
    int c = 1;
    while (pNode != NULL)
    {
        printf("Item %d is: %d\n", c++, pNode->data);
        pNode = pNode->pNext; //Set pointer for Node to the next Node
    } // will keep recurring till reaches Node with NULL data (original pHead)
}

void addNodeAtHead(Node** pHead, int value)
{
    Node *pNode = malloc(1 * sizeof(Node)); // allocate at least 1 Node size first
    pNode->data = value; // dereference pNode data and set it equal to value passed
    pNode->pNext = *pHead; // dereference pNext and set it to address of pHead
    *pHead = pNode; // pHead in main will now be set to the pNode

    // final order: new pHead (which is pNode) -> old pHead(which is NULL)
}

void countNodes(Node** pHead)
{
    Node *pNode = *pHead;
    int c = 0;
    while (pNode != NULL)
    {
        pNode = pNode->pNext; //Set pointer for Node to the next Node
        c++;
    }

    printf("The number of Nodes is: %d\n", c);
}

void countValue(Node** pHead, int value)
{
    Node *pNode = *pHead;
    int c = 0;
    while (pNode != NULL)
    {
        if(pNode->data == value)
        {
            c++;
        }
        pNode = pNode->pNext; //Set pointer for Node to the next Node
    }

    printf("The number of %d\'s is: %d\n", value, c);
}