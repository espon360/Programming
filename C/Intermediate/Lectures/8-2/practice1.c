#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _BNode
{
    int data;
    struct _bNode *left;
    struct _bNode *right;
} BNode;

BNode *addNode(int data); // will create a node with data argument and return pointer
void insertNode(BNode *pNode, int data); // insert a node

int main(void)
{
    BNode *pRoot = addNode(4); // Add data of 4 to the first node (root)

    insertNode(pRoot, 2);
    insertNode(pRoot, 6);
}

BNode *addNode(int data) 
{
    BNode *pNode = malloc(1 * sizeof(BNode));
    pNode->data = data;
    pNode->left = NULL;
    pNode->right = NULL; 
    return pNode;
}

void insertNode(BNode *pNode, int data)
{
    if(pNode != NULL) // if node exists
    {
        if(data < pNode->data) // if data you're adding is less than pNode data, add to left
        {
            if(pNode->left == NULL) // check to see if left of pNode is already empty
            {
                pNode->left = addNode(data); // left node will now point to the new created node with the addNode function with data argument
            }
            else
            {
                insertNode(pNode->left, data); // recursion in case the left node is occupied then keeps going down the tree in depth
            }
        }
        else // add right node if data is greater or equal to
        {
            if(pNode->right == NULL)
            {
                pNode->right = addNode(data);
            }
            else
            {
                insertNode(pNode->right, data);
            }
        }
    }
}