/**
FILENAME:BOARD.C
CREATED BY:DICKY LARSON GULTOM 19487537
PURPOSE: CREATING THE BOARD AND CONTROLLING THE GAME
GITHUB REPOSITORY : https://github.com/mutsuuuuuuu/UCP-Assignment-SEM2-2019
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "board.h"
#include "log.h"
#include "LinkedList.h"
#define TRUE 1
#define FALSE 0
void createBoard(LinkedList *newList, int m, int n, int k)
{
    char **board;
    int i,j;


    printf("ROW SIZE: %d, COLUMN SIZE: %d\n",m,n);
    /**create array with m rows**/
    board = (char**)malloc(sizeof(char*)*m);

    /**create array with n column**/
    for(i = 0; i<m; i++)
    {
        board[i] = (char*)malloc(sizeof(char)*n);
    }
    
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            board[i][j]= ' ';
        }
    }

    printBoard(board,m,n);
    playGame(newList,board,m,n,k);
    freeBoard(board,m);
}

void playGame(LinkedList *list,char **board, int m, int n, int k)
{
    int prevPlayer,player,loc1,loc2,turn;
    logs *logging;
    /*player 1 start */
    player = 1;
    /**initialise turn count**/
    turn = 0;
    /** loop player turn while prev player not win**/
    do
    {
        if(player == 1)
        {       
            printf("Player %d turn\n",player);
            do /**keep asking for player one input until the player choose an empty slot **/
            {
                do /**keep looping first location untul its between 0 and m-1**/
                {
                    printf("Enter the first Location (Y):\n");
                    scanf(" %d",&loc1);
                    if(loc1 < 0)
                    {
                        printf("Invalid location: %d\n Min value is 0",loc1);
                    }
                    else if (loc1 > m)
                    {
                        printf("Invalid location : %d\n Min value is %d",loc1,m-1);
                    }   
                }
                while(loc1 < 0 || loc1 > m-1);
                do /**keep looping the second location until its between 0 and n-1**/
                {
                    printf("Enter the second location (X):\n");
                    scanf(" %d",&loc2);
                    if(loc2<0)
                    {
                        printf("Invalid Location : %d\n Min value is 0",loc2);
                    }
                    else if(loc2>n)
                    {
                        printf("Invalid Location : %d\n Max value is %d",loc2,n-1);
                    }
                }
                while(loc2<0 || loc2 > n-1);

                if(board[loc1][loc2] != ' ' || board[loc1][loc2] == 'O')
                {
                    printf("That location has been occupied\n");
                }
            }
            while(board[loc1][loc2] != ' ');
            board[loc1][loc2] = 'X';
        }
        else if(player == 2)
        {
            do
            {
                printf("Player %d turn\n",player);
                do
                {
                    printf("Enter the first location (Y):\n");
                    scanf("%d",&loc1);
                    if(loc1 < 0)
                    {
                        printf("Invalid Location : %d\n Min value is 0",loc1);
                    }
                    else if(loc1 > m-1)
                    {
                        printf("Invalid Location : %d\n Max value is %d",loc1,m-1);
                    }
                }
                while(loc1<0 || loc1 > m-1);

                do
                {
                    printf("Enter the second location (X):\n");
                    scanf("%d",&loc2);
                    if(loc2<0)
                    {
                        printf("Invalid Location : %d\n Min value is 0",loc2);
                    }
                    else if(loc2>n-1)
                    {
                        printf("Invalid location : %d\n Max value is %d",loc2,n-1);
                    }
                }
                while(loc2<0 || loc2>n-1);
            }
            while(board[loc1][loc2] != ' ');
            board[loc1][loc2] = 'O';
        }
        /** player turn has finish**/
        /** print board**/
        printBoard(board,m,n);
        
        /*swap the player*/
        if(player == 1)
        {
            player++;
            prevPlayer = 1;
        }
        else if(player == 2)
        {
            player--;
            prevPlayer = 2;
        }
        printf("Player %d turn has finished\n",prevPlayer);
        turn++;
        logging = constructStruct(turn,prevPlayer,loc1,loc2);
        insertLast(list,logging);    
    } 
    while(checkWin(board,m,n,k,prevPlayer,loc1,loc2)==TRUE);

    printf("Player %d won\n",prevPlayer);
}

void printBoard(char **board, int m, int n)
{
    int i,j;
    for(i=0; i<m; i++)
    {
        printf("||");
        for(j=0; j<n; j++)
        {
            printf("| %c |",board[i][j]); 
        }
        printf("|| \n");
        printf("---------------------------\n");
    }
}


int checkWin(char **board, int m, int n, int k, int player,int loc1, int loc2)
{
    int Notwinning;

    Notwinning = TRUE;
    if(checkVertical(board,m,k,loc2,player) == 1 || checkHorizontal(board,n,k,loc1,player)==1||
    checkDiagonal(board,m,n,k,loc1,loc2,player) == 1)
    {
        Notwinning = FALSE;
    }
    
    return Notwinning;
}

int checkVertical(char **board, int m,int k,int loc2,int player)
{
    int count,i;
    int win; 
    win = FALSE;
    count  = 0; 
    if(player == 1)
    {
        for(i = 0; i<m; i++)
        {
            if(board[i][loc2] == 'X')
            {
                count++;
                if(count == k)
                {
                    win = TRUE;
                }
            }
            else if(board[i][loc2] == ' ' || board[i][loc2] == 'O')
            {
                count = 0;
            }
        }
    }
    else if(player == 2)
    {
        for(i=0; i<m; i++)
        {
            if(board[i][loc2] == 'O')
            {
                count++;
                if(count == k)
                {
                    win = TRUE;
                }
            }
            else if(board[i][loc2] == ' '|| board[i][loc2] == 'X')
            {
                count = 0;
            }
        }
    }
    return win;
}

int checkHorizontal(char **board, int n, int k, int loc1, int player)
{
    int win,count,i;
    win  = FALSE;
    count = 0;
    
    if(player == 1)
    {
        for(i=0; i<n; i++)
        {
            if(board[loc1][i] == 'X')
            {
                count++;
                if(count ==k)
                {
                    win=TRUE;
                }
            }
            else if(board[loc1][i] == ' '||board[loc1][i] == 'O')
            {
                count = 0;
            }
        }
    }
    else if(player == 2)
    {
        for(i=0;i<n;i++)
        {
            if(board[loc1][i] == 'O')
            {
                count++;
                if(count == k)
                {
                    win = TRUE;
                }   
            }
            else if(board[loc1][i] == ' '||board[loc1][i] == 'X')
            {
                count=0;
            }
        }
    }
    return win;
}

int checkDiagonal(char **board, int m, int n, int k,int loc1, int loc2, int player)
{
    int win,count,pnt1,pnt2,pnt3,pnt4;

    win = FALSE;
    pnt1=loc1;
    pnt3=loc1;
    
    pnt2=loc2;
    pnt4=loc2;
    count = 0;
    if(player == 1)
    {
        /**if its already on top then **/
        
        /**getting the most northwest diagonal position **/
        while(pnt1 != 0 && pnt2 != 0)
        {
            pnt1--;
            pnt2--;
        }
        /**getting the most northeast diagonal position **/
        while(pnt3 != 0 && pnt4 != n-1)
        {
            pnt3--;
            pnt4++;
        }
            
        /**loop through the northwest diagonal to southeast diagonal **/
        while(pnt1 != m && pnt2 != n)
        {
            if(board[pnt1][pnt2] == 'X')
            {
                count++;
                if(count==k)
                {
                    win = TRUE;
                }
            }
            else if(board[pnt1][pnt2] == ' ' || board[pnt1][pnt2] == 'O')
            {
                count=0;
            }
            pnt1++;
            pnt2++;
        }
        /**loop the other way**/
        while(pnt3 != m && pnt4 !=0)
        {
            if(board[pnt3][pnt4] == 'X')
            {
                count++;
                if(count==k)
                {
                    win=TRUE;
                }
            }
            else if(board[pnt3][pnt4] == ' ' || board[pnt3][pnt4] =='O')
            {
                count=0;
            }
            pnt3++;
            pnt4--;
        }
    }
    else if(player==2)
    {
	/**getting the most northwest diagonal position **/
        while(pnt1 != 0 && pnt2 != 0)
        {
            pnt1--;
            pnt2--;
        }
        /**getting the most northeast diagonal position **/
        while(pnt3 != 0 && pnt4 != n-1)
        {
            pnt3--;
            pnt4++;
        }
            
        /**loop through the northwest diagonal to southeast diagonal **/
        while(pnt1 != m && pnt2 != n)
        {
            if(board[pnt1][pnt2] == 'O')
            {
                count++;
                if(count==k)
                {
                    win = TRUE;
                }
            }
            else if(board[pnt1][pnt2] == ' ' || board[pnt1][pnt2] == 'X')
            {
                count=0;
            }
            pnt1++;
            pnt2++;
        }
        /**loop the other way**/
        while(pnt3 != m && pnt4 !=0)
        {
            if(board[pnt3][pnt4] == 'O')
            {
                count++;
                if(count==k)
                {
                    win=TRUE;
                }
            }
            else if(board[pnt3][pnt4] == ' ' || board[pnt3][pnt4] =='X')
            {
                count=0;
            }
            pnt3++;
            pnt4--;
        }
    }
        
    return win;
}

void freeBoard(char **board, int m)
{   
    int i;
    for(i=0; i<m; i++)
    {
        free(board[i]);
    }
    free(board);
}
   
