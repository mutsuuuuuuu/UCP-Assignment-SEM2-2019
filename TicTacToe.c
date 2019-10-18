/** STANDARD C HEADER FILE **/
#include <stdio.h>
#include <stdlib.h>

/** CUSTOM C HEADER FILE**/
#include "TicTacToe.h"
#include "readFile.h"

int main(int argc, char *argv[])
{
    int *m,*n,*k,menuSelection;
    int zerom,zeron,zerok;
    zerom = 0; zeron = 0; zerok=0;
    m = &zerom;
    n = &zeron;
    k = &zerok;
    if(argc < 2)
    {
        printf("The command line argument is invalid or null\n");
        printf("./TicTacToe [file Setting Name]\n");
    }
    else
    {
        do
            {
                printf("======================================\n");
                printf("WELCOME TO THE WORLD WORST TIC TAC TOE\n");
                printf("======================================\n");

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
                        readFile(argv[1],m,n,k);
                        if(m == 0 || n==0 || k ==0)
                        {
                            if(m==0)
                            {
                                printf("Please fix the value of M. The value of M is currently 0\n");
                            }
                            else if(n==0)
                            {
                                printf("Please fix the value of N. The current value of N is 0\n");
                            }
                            else if(k==0)
                            {
                                printf("Please fix the value of K. The current value of %d\n",*k);
                            }
                        } 
                        else
                        {
                            /* Play the game */
                            createBoard(*m,*n,*k);
                        }
                        break;
                    case 2:
                        printf("Viewing Setting:\n");
                        printf("M =  %d\n",*m);
                        printf("N = %d\n",*n);
                        printf("K = %d\n",*k);
                        break;
                    case 3:
                        break;
                    case 4:
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
    }
    return 0;
}
