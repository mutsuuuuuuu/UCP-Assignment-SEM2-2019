/**
FILENAME: LOG.C
PURPOSE: CREATES A LOG STRUCT AND ALSO HOLDS METHOD TO PRINT THE CONTENT OF THE STRUCT TO TERMINAL AND FILE.
GITHUB REPOSITORY : https://github.com/mutsuuuuuuu/UCP-Assignment-SEM2-2019
**/

#include <stdlib.h>
#include <stdio.h>
#include "log.h"

logs *constructStruct(int inGame, int inPlayer, int loc1, int loc2)
{
    logs *obj;
    obj = (logs*)malloc(sizeof(logs));
    obj->turn = inGame;
    obj->player = inPlayer;
    obj->location1 = loc1;
    obj->location2 = loc2;

    return obj;
}

void printLog(logs *data)
{
    printf("TURN:   %d\n",data->turn);
    printf("PLAYER: %d\n",data->player);
    printf("LOCATION X: %d\n",data->location2);
    printf("LOCATION Y: %d\n",data->location1);
printf("\n");
}

void writeData(FILE *output, logs *data)
{
	fprintf(output,"TURN: %d\n",data->turn);
	fprintf(output,"PLAYER: %d\n",data->player);
	fprintf(output,"LOCATION X: %d\n",data->location2);
	fprintf(output,"LOCATION Y: %d\n",data->location1);
	
	fprintf(output,"\n");
}

void freeLog(logs *data)
{
    free(data);
}

