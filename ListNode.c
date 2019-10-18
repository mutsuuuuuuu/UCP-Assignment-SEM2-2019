#include <stdlib.h>
#include "ListNode.h"

Node *createNode(logs *data)
{
    Node *newNd;
    newNd = (Node*)malloc(sizeof(Node));
    
    newNd->data= Logs;

    return newNd;
}

void freeNode(Node *node)
{
    /**free the data**/

    /** free the node **/
}
