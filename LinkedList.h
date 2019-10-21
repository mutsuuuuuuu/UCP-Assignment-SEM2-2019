#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>

#include "ListNode.h"
#include "log.h"


typedef struct LL
{
    Node *head;
    Node *tail;
    int count;
}LinkedList;

LinkedList *createLinkedList();
void insertFirst(LinkedList *list, logs *data);
int isEmpty(LinkedList *list);
void printList(LinkedList *list);
void insertLast(LinkedList *list, logs *data);
void freeList(LinkedList *list);
void writeTofile(FILE *output, LinkedList *list);
#endif

