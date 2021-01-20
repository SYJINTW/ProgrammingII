#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n ,&m);
    int cArray[1000];
    int aArray[1000];
    for(int i=0 ; i<n ; ++i){
        int temp;
        scanf("%d", &temp);
        cArray[i] = temp;
    }
    for(int i=0 ; i<m ; ++i){
        int temp;
        scanf("%d", &temp);
        aArray[i] = temp;
    }
    int i=0, j=0, ans=0;
    while(i<n && j<m){
        if(aArray[j] >= cArray[i]){
            i++;
            j++;
            ans++;
        }else{
            i++;
        }
    }
    printf("%d\n", ans);

    return 0;
}