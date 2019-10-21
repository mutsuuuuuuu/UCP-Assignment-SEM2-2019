/**
FILENAME: TicTacToe.c
CREATED BY:DICKY LARSON GULTOM 19487537
PURPOSE: Holds the main function to run the program.
GITHUB REPOSITORY : https://github.com/mutsuuuuuuu/UCP-Assignment-SEM2-2019
**/

/** STANDARD C HEADER FILE **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/** CUSTOM C HEADER FILE**/
#include "LinkedList.h"
#include "userInterface.h"
#include "TicTacToe.h"


int main(int argc, char *argv[])
{
	LinkedList *logList;
	logList = NULL;
    if(argc < 2)
    {
        printf("The command line argument is invalid or null\n");
        printf("./TicTacToe [file Setting Name]\n");
    }
    else
    {
        logList=createLinkedList();

        #ifdef DEFAULT
		    defaultMode(logList,argv[1]); 
        #endif

        #ifdef SECRET
            secretMode(logList,argv[1]);
        #endif

        #ifdef EDITOR
            editorMode(logList,argv[1]);
        #endif
    }
    return 0;
}
