#include <stdio.h>
#include <stdlib.h>
#include "function.h"

static char map[5][5]={{'1'}};

int main()
{
    int i,j;
    setmap();//defined in function.c
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
