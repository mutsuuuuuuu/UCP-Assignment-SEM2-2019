#include <stdlib.h>
#include <stdio.h>
#include "log.h"

logs *constructStruct(int inGame, char inPlayer, int loc1, int loc2);
{
    logs *obj;
    obj = (logs*)malloc(sizeof(logs));
    obj->turn = inGame;
    obj->player = inPlayer;
    obj->location1 = loc1;
    obj->location2 = loc2;

    return obj;
}

void freelog(logs *data)
{
    free(data);
}

