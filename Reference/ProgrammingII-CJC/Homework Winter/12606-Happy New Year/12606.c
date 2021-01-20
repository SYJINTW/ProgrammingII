#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int N;
    scanf("%d", &N);
    
    int min = INT_MAX, max = -1;
    for(int i=0 ; i<=N ; ++i){
        int cur;
        scanf("%d", &cur);
        if(cur < min)
            min = cur;
        if(cur > max)
            max = cur;
    }
    printf("%d\n", (max-min)*2);
    return 0;
}