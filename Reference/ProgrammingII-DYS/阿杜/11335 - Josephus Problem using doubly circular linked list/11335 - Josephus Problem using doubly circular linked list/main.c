#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main(){

    int n, m;

    while(scanf("%d%d", &n, &m)!=EOF){
        head = createList(n);
        printf("%d\n", solveJosephus(m));
        freeList();
    }

    return 0;
}
