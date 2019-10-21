#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "LinkedList.h"

void defaultMode(LinkedList *list, char *filename);
void secretMode(LinkedList *list, char *filename);
void editorMode(LinkedList *list, char *filename);
void changeValue(int *m, int *n, int *k);
#endif
