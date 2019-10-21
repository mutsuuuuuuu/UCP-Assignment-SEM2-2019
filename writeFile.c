/**
FILENAME: writeFile.c
CREATED BY:DICKY LARSON GULTOM 19487537
PURPOSE: printing all of the contents inside the linked list to a file.
GITHUB REPOSITORY : https://github.com/mutsuuuuuuu/UCP-Assignment-SEM2-2019
**/

#include <time.h>
#include <stdio.h>
#include "LinkedList.h"
#include "writeFile.h"
void writeLog(LinkedList *list,int m, int n, int k)
{
    FILE *output;
    int hour,min,day,month;
    char str[300];
    struct tm *cur;
    time_t currentTime;
    time(&currentTime);
    
    cur = localtime(&currentTime);
    hour = cur->tm_hour;
    min  = cur->tm_min;

    day = cur->tm_mday;
    month = cur->tm_mon+1;

    sprintf(str, "M-N-K_%d-%d-%d_%d-%d_%d-%d.log",m,n,k,hour,min,day,month); 
    output = fopen(str,"w");
    
    if(output == NULL)
    {
        perror("Error while opening file\n");
    }
    else
    {
        writeTofile(output,list);
    }
    fclose(output);
}
