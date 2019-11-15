/**
FILENAME: LISTNODE.C
PURPOSE: CREATING A LINKED LIST NODE AND HOLDS THE METHOD FREE TO FREE THE NODE.
GITHUB REPOSITORY : https://github.com/mutsuuuuuuu/UCP-Assignment-SEM2-2019
**/
#include <stdlib.h>
#include <stdio.h>
#include "ListNode.h"
#include "log.h"

Node *createNode(logs *value)
{
    Node *newNd;
    newNd = (Node*)malloc(sizeof(Node));
    
    newNd->data=value;

    return newNd;
}

void freeNode(Node *node)
{
    /**free the data**/
	freeLog(node->data);

    /** free the node **/
	free(node);
}

void writeNode(FILE *output, Node *node)
{
}
