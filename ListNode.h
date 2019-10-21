#ifndef LISTNODE_H
#define LISTNODE_H

#include "log.h"
#include <stdio.h>
typedef struct ListNode
{
    logs *data;
    struct ListNode *prev;
    struct ListNode *next; 
}Node;

Node *createNode(logs *value);
void freeNode(Node *node);
void writeNode(FILE *output, Node *node);
#endif
