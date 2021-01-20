#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char str[10001];
    scanf("%s", str);
    int m=0;
    scanf("%d", &m);

    for(int i=0 ; i<m ; ++i){
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        l -= 1;
        r -= 1;
        int len = r-l+1;
        k %= len;
        // for(int i=0 ; i<k ; ++i){
        //     int temp = str[r];
        //     for(int j=r ; j>l ; --j){
        //         str[j] = str[j-1];
        //     }
        //     str[l] = temp;
        //     // printf("i = %d ,str = %s\n",i , str);
        // }
        char sub_str[10001];
        strncpy(sub_str, str+l, len);
        for(int i=0 ; i<len ; ++i){
            str[l + (i + k)%len] = sub_str[i];
        }
        
    }
    printf("%s\n", str);

    return 0;
}