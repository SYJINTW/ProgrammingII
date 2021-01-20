#include <stdio.h>
#include "function.h"

static char map[5][5]={{'\0'}};

void setmap(void)
{
    int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++){
            map[i][j] = '2';
        }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }
}
