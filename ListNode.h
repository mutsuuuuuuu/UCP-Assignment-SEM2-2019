#ifndef LISTNODE_H
#define LISTNODE_H

#include "log.h"

typedef struct ListNode
{
    logs *Log;
    struct ListNode *prev;
    struct ListNode *next; 
}Node;

Node *createNode(logs *data);
#endif
