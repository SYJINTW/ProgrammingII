#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define maxN 200001

int main(){
    int n;
    scanf("%d", &n);

    char str[maxN];
    scanf("%s", &str[0]);

    int mostR = -1;
    int ans = INT_MAX;

    for(int i=0 ; i<n ; ++i){
        int position;
        scanf("%d", &position);

        if(str[i] == 'R'){
            mostR = position;
        }
        else if(str[i] == 'L'){
            if(mostR == -1)
                continue;
            ans = ans < (position-mostR)/2 ? ans : (position-mostR)/2;
        }
    }
    printf("%d\n", ans == INT_MAX ? -1 : ans);
}