#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int t;
    scanf("%d", &t);

    for(int i=0 ; i<t ; ++i){
        int a, b;
        int ans = 0;
        scanf("%d %d", &a, &b);
        printf("%.0f\n", a*floor(log10(b+1)));
    }
    

    return 0;
}