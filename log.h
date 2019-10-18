#ifndef LOG_H
#define LOG_H
typedef struct Log
{
    int turn;
    char player;
    int location1;
    int location2;
} logs;


logs *constructStruct(int inGame, char inPlayer, int loc1, int loc2);
void freelog(logs *data);

#endif
