#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "readFile.h"

void readFile(char *Filename, int *m, int *n, int *k)
{
    int count,number,mvalue,kvalue,nvalue;
    char str;
    FILE *input;
    mvalue = 0;
    nvalue = 0;
    kvalue = 0;
    input = fopen(Filename,"r");

    if(input == NULL)
    {
        perror("ERROR WHILE READING THE FILE");
    }
    else
    {
        /**read the file**/
        for(count = 0; count < 3; count++)
        {
            fscanf(input," %c=%d",&str,&number);
            if(toupper(str)=='M')
            {
                mvalue = number;
                *m = mvalue;
            }
            else if(toupper(str)=='N')
            {
                nvalue = number;
                *n = nvalue;
            }
            else if(toupper(str)=='K')
            {
                kvalue = number;
                *k = kvalue;
            }
                
        }
    }
    fclose(input);
}           
