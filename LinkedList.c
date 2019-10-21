/**
FILENAME: LINKEDLIST.C
CREATED BY:DICKY LARSON GULTOM 19487537
PURPOSE: CREATING LINKEDLIST STRUCT OBJECT AND HOLDS LINKEDLIST METHODS
GITHUB REPOSITORY : https://github.com/mutsuuuuuuu/UCP-Assignment-SEM2-2019
**/

#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#include <stdio.h>
#include "ListNode.h"
#include "LinkedList.h"
#include "log.h"

LinkedList* createLinkedList()
{
    LinkedList *list;
    list = (LinkedList*)malloc(sizeof(LinkedList)); 
    list->head = NULL;
    list->tail = NULL;

    return list;
}
void insertLast(LinkedList *list, logs *data)
{
    Node *newNode;
    newNode = createNode(data);
    if(list->head == NULL && list->tail == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        newNode->next = NULL;
        list->tail=newNode;
    }
}
void insertFirst(LinkedList *list, logs *data)
{
    Node *newNode;
    newNode = createNode(data);
    if(isEmpty(list) == TRUE)
    {
        list->tail = newNode;
        list->head = newNode;
    }
    else
    {
        newNode->next = list->head;
        newNode->prev = NULL;
        list->head->prev = newNode;
        list->head = newNode;
    }
}
void printList(LinkedList *list)
{
    Node *currNd;
    if(list->tail == NULL)
    {
        printf("Log is empty\n");   
    }
    else
    {
        currNd = list->head;
        while(currNd->next != NULL)
        {
            printLog(currNd->data);
	        currNd = currNd->next;
        }
	currNd = list->tail;
	printLog(currNd->data);
    }
}

int isEmpty(LinkedList *list)
{
    int isEmpty;
    isEmpty = FALSE;

    if(list->head == NULL || list->tail == NULL)
    {
        isEmpty=TRUE;
    }
    return isEmpty;
}

void freeList(LinkedList *list)
{
	Node *currNd;
	currNd=list->head;
	while(currNd->next !=NULL)
	{
		freeNode(currNd);
		currNd=currNd->next;
	}
	currNd = list ->tail;
	freeNode(currNd);

	free(list);
}

void writeTofile(FILE *output, LinkedList *list)
{
	Node *currNd;
    if(list->head == NULL)
    {
        printf("Linked List Log is empty. Cannot Write to File\n");
    }
    else
    {
    currNd = list->head;
	while(currNd->next != NULL)
	{
		writeData(output,currNd->data);
		currNd=currNd->next;
	}

	currNd = list->tail;
	writeData(output,currNd->data);
    }
}
