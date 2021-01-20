#include <stdio.h>
#include "function.h"

char map[5][5]={{'\0'}};//the defining declaration

void setmap(void)
{
    int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++){
            map[i][j] = '2';
        }
}
