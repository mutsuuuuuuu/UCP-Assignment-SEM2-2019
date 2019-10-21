#ifndef LOG_H
#define LOG_H
#include <stdio.h>
typedef struct Log
{
    int turn;
    int player;
    int location1;
    int location2;
}logs;


logs *constructStruct(int inGame, int inPlayer, int loc1, int loc2);
void freeLog(logs *data);
void printLog(logs *data);
void writeData(FILE *output, logs *data);
#endif
