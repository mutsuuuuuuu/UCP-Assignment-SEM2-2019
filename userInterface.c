/**
FILENAME: userInterface.c
CREATED BY:DICKY LARSON GULTOM 19487537
PURPOSE: holds every menu interface for each program mode.
GITHUB REPOSITORY : https://github.com/mutsuuuuuuu/UCP-Assignment-SEM2-2019
**/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "userInterface.h"
#include "board.h"
#include "readFile.h"
#include "writeFile.h"
void defaultMode(LinkedList *logList, char* filename)
{
    int *m,*n,*k,menuSelection;
    int zerom,zeron,zerok,gamecount;
    zerom = 0; 
    zeron = 0; 
    zerok=0;
    
    m = &zerom;
    n = &zeron;
    k = &zerok;
    gamecount=0; 
    do
        {
            printf("======================================\n");
            printf("WELCOME TO THE WORLD WORST TIC TAC TOE\n");
            printf("======================================\n");
            
            printf("\n");
            printf("NOTE: You are currently running the default mode of the game");
            printf("\n");

            printf("Please choose\n"
                   "1: Start a new game\n"
                   "2: View the settings of the game\n"
                   "3: View the current logs\n"
                   "4: Save the logs to a file\n"
                   "5: Exit the application\n");
            scanf("%d",&menuSelection);
            switch (menuSelection)
            {
                case 1:
                    readFile(filename,m,n,k);
                    if(*m == 0 || *n==0 || *k ==0)
                    {
                        if(*m==0)
                        {
                            printf("Please fix the value of M. The value of M is currently 0\n");
                        }
                        else if(*n==0)
                        {
                            printf("Please fix the value of N. The current value of N is 0\n");
                        }
                        else if(*k==0)
                        {
                            printf("Please fix the value of K. The current value of %d\n",*k);
                        }
                    }
                    else if(*m<3 || *n <3)
                    {
                        printf("Please fix the value of M and/or N. The value of M and N cannot fall below 3\n");
                        printf("Current Value of \n M: %d N: %d\n",*m,*n);
                    }
                    else if(*k>*m || *k>*n)
                    {
                        printf("Please fix the value of K. The value of K cannot exceed the value of M and N\n");
                    }
                    else if(*k<=2)
                    {
                        printf("Please Fix the value of K. Cannot have a K value of less than 2\n");   
                    } 
                    else
                    {
                            /* Play the game */
                        createBoard(logList,*m,*n,*k);
			            gamecount++;
                    }
                    break;

                    case 2:
			            readFile(filename,m,n,k);
                        printf("Viewing Setting:\n");
                        printf("M =  %d\n",*m);
                        printf("N = %d\n",*n);
                        printf("K = %d\n",*k);
                        break;

                    case 3:
			            printf("\n");
			            printList(logList);
			            printf("\n");
                        break;

                    case 4:
                        writeLog(logList,*m,*n,*k); 
                        break;

                    case 5:
                        printf("EXITING THE TIC TAC TOE GAME\n");
                        printf("GOODBYE \n");
                        break;

                    default:
                        printf("Invalid Menu\n");
                }
            }
            while (menuSelection > 0 && menuSelection < 5);

	    /**free goes here**/
        if(gamecount == 0)
        {
            free(logList);
        }
        else
        {
	        freeList(logList);
        }
}

void editorMode(LinkedList *logList,char *filename)
{
	int *m,*n,*k,menuSelection;
    int zerom,zeron,zerok,gamecount;
    zerom = 0; 
    zeron = 0; 
    zerok=0;
    
    m = &zerom;
    n = &zeron;
    k = &zerok;
    gamecount=0;

	readFile(filename,m,n,k);

    do
    {
        printf("======================================\n");
        printf("WELCOME TO THE WORLD WORST TIC TAC TOE\n");
        printf("======================================\n");
        printf("\n");
        
        printf("NOTE: You are currently running the editor mode of the game");
        printf("\n");

        printf("Please choose\n"
        "1: Start a new game\n"
        "2: View the settings of the game\n"
		"3: Change the Value of M-N-K\n"
        "4: View the current logs\n"
        "5: Save the logs to a file\n"
        "6: Exit the application\n");
        scanf("%d",&menuSelection);
        switch (menuSelection)
        {
            /**play the game**/
            case 1:
                if(*m == 0 || *n==0 || *k ==0)
                {
                    if(*m==0)
                    {
                        printf("Please fix the value of M. The value of M is currently 0\n");
                    }
                    else if(*n==0)
                    {
                        printf("Please fix the value of N. The current value of N is 0\n");
                    }
                    else if(*k==0)
                    {
                        printf("Please fix the value of K. The current value of %d\n",*k);
                    }
                }
                else if(*m<3 || *n <3)
                {
                    printf("Please fix the value of M and/or N. The value of M and N cannot fall below 3\n");
                    printf("Current Value of \n M: %d N: %d\n",*m,*n);
                }
                else if(*k>*m || *k>*n)
                {
                    printf("Please fix the value of K. The value of K cannot exceed the value of M and N\n");
                }
                else if(*k<=2)
                {
                    printf("Please Fix the value of K. Cannot have a K value of less than 2\n");   
                } 
                else
                {
                    /* Play the game */
                    createBoard(logList,*m,*n,*k);
				    gamecount++;
                }
                break;
        
                /**View Setting**/
            case 2:
                printf("Viewing Setting:\n");
                printf("M =  %d\n",*m);
                printf("N = %d\n",*n);
                printf("K = %d\n",*k);
                break;

              /**change value**/
		    case 3:
                changeValue(m,n,k);
			    break;

                    /**Printing Log**/
            case 4:
			    printf("\n");
			    printList(logList);
			    printf("\n");
                break;

             /**write Log to File**/
            case 5:
                writeLog(logList,*m,*n,*k); 
                break;

             /**Exit**/
            case 6:
                printf("EXITING THE TIC TAC TOE GAME\n");
                printf("GOODBYE \n");
                break;
        
            default:
                printf("Invalid Menu\n");
                }
            }
            while (menuSelection > 0 && menuSelection < 6);

	    /**free goes here**/
        if(gamecount == 0)
        {
            free(logList);
        }
        else
        {
	        freeList(logList);
        }
	
}

void changeValue(int *m, int *n, int *k)
{
	int menu,newM,newN,newK;
	do
	{
	    printf("Please choose which variable you want to change\n"
		    "1: Change the value of M\n"
		    "2: Change the value of N\n"
		    "3: Change the value of K\n"
		    "4: Exit\n");
    	scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                printf("Please enter the new Value of M\n");
                scanf("%d",&newM);
                *m = newM;
            break;
            
            case 2:
                printf("Please enter the new value of N\n");
                scanf("%d",&newN);
                *n = newN;
                break;
            
            case 3:
                printf("Please enter the new value of K\n");
                scanf("%d",&newK);
                *k = newK;
            break;
            
            case 4:
            break;
            
            default:
                printf("Invalid Input\n");
        }
    }
    while(menu>0 && menu <4);
    
}

void secretMode(LinkedList *list,char *filename)
{
	int *m,*n,*k,menuSelection;
    int zerom,zeron,zerok,gamecount;
    LinkedList *logList; 
    logList = NULL; 
    zerom = 0; 
    zeron = 0; 
    zerok=0;
    
    m = &zerom;
    n = &zeron;
    k = &zerok;
    gamecount=0;

    do
    {
        printf("=====================================================\n");
        printf("WELCOME TO THE WORLD WORST TIC TAC TOE IN SECRET MODE\n");
        printf("=====================================================\n");
        
        printf("\n");
        printf("NOTE: You are currently running the secret mode of the game");
        printf("\n");
        printf("Please choose\n"
                "1: Start a new game\n"
                "2: View the settings of the game\n"
                "3: View the current logs\n"
                "4: Exit the application\n");
        scanf("%d",&menuSelection);
        switch (menuSelection)
        {
            case 1:
                readFile(filename,m,n,k);
                if(*m == 0 || *n==0 || *k ==0)
                {
                    if(*m==0)
                    {
                        printf("Please fix the value of M. The value of M is currently 0\n");
                    }
                    else if(*n==0)
                    {
                        printf("Please fix the value of N. The current value of N is 0\n");
                    }
                    else if(*k==0)
                    {
                        printf("Please fix the value of K. The current value of %d\n",*k);
                    }
                }
                else if(*m<3 || *n <3)
                {
                    printf("Please fix the value of M and/or N. The value of M and N cannot fall below 3\n");
                    printf("Current Value of \n M: %d N: %d\n",*m,*n);
                }
                else if(*k>*m || *k>*n)
                {
                    printf("Please fix the value of K. The value of K cannot exceed the value of M and N\n");
                }
                else if(*k<=2)
                {
                    printf("Please Fix the value of K. Cannot have a K value of less than 2\n");   
                } 
                else
                {
                    /* Play the game */
                    createBoard(logList,*m,*n,*k);
				    gamecount++;
                }
                break;

                case 2:
			        readFile(filename,m,n,k);
                    printf("Viewing Setting:\n");
                    printf("M =  %d\n",*m);
                    printf("N = %d\n",*n);
                    printf("K = %d\n",*k);
                    break;

                case 3:
			        printf("\n");
			        printList(logList);
			        printf("\n");
                    break;

                case 4:
                    printf("EXITING THE TIC TAC TOE GAME\n");
                    printf("GOODBYE \n");
                    break;

                default:
                    printf("Invalid Menu\n");
                }
            }
            while (menuSelection > 0 && menuSelection < 4);

	    /**free goes here**/
        if(gamecount == 0)
        {
            free(logList);
        }
        else
        {
	        freeList(logList);
        }
}

