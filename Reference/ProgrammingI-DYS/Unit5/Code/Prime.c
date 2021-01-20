#include <stdio.h>
#define N 120

int A[N+1];

int main(void)
{
    int i,j;

    for(i = 0;i<=N;i++)
        A[i] = 1;

    for(i = 2;i*i<=N;i++){
        if(A[i] == 1){
            for(j=i*i;j<=N;j+=i){
                A[j] = 0;
            }
        }
    }

    for(i = 2;i<=N;i++){
        if(A[i] == 1)
            printf("%d\n",i);
    }

    return 0;
}
