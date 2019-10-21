#ifndef BOARD_H
#define BOARD_H
#include <stdbool.h>
#include "LinkedList.h"
void createBoard(LinkedList *newList,int m, int n, int k);
void printBoard(char **board, int m, int n);
void playGame(LinkedList * list,char **board, int m, int n, int k);
void freeBoard(char **board, int m);
int checkWin(char **board, int m, int n, int k,int player,int loc1,int loc2);
int checkVertical(char **board, int m, int k,int loc2, int player); 
int checkHorizontal(char **board, int n, int k, int loc1, int player);
int checkDiagonal(char **board, int m, int n, int k, int loc1, int loc2, int player);
#endif
