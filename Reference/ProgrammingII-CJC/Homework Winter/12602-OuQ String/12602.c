#include <stdio.h>
#include <stdlib.h>

int k;
long long l, r, temp, len[51];


void rec(int k){
    if(temp + len[k] <= l){
        temp += len[k];
        // printf("k = %d\ntemp = %lld\n",k , temp);
    }else if(temp <= r){
        if(temp >= l && temp <= r)
            printf("O");
        temp++;

        if(k != 1 && temp <= r)
            rec(k-1);

        if(temp >= l && temp <= r)
            printf("u");
        temp++;

        if(k != 1 && temp <= r)
            rec(k-1);
            
        if(temp >= l && temp <= r)
            printf("Q");
        temp++; 
    }
}

long long lenk(int k){
    if(len[k]) 
        return len[k];
    if(k == 1)
        return len[1] = 3;
    return len[k] = 3 + 2 * lenk(k-1);
}

int main(){
    lenk(50);
    while(scanf("%d %lld %lld", &k, &l, &r) != EOF){
        temp = 0;
        rec(k);
        printf("\n");
    }

    return 0;
}

