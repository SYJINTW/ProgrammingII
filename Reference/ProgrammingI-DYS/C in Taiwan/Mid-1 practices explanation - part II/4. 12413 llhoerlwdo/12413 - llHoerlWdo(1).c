#include<stdio.h>

int main(void)
{
    int M, N, T, A[1000], B[1000];
    char str[1000][1000], tmp;

    scanf("%d%d%d", &M, &N, &T);
    getchar();

    for (int r=0; r<M; r++) {
        for (int c=0; c<N; c++) {
            scanf("%c", &str[r][c]);
            getchar();
        }
    }

    for (int t=0; t<T; t++) {
        scanf("%d%d", &A[t], &B[t]);
        A[t] = A[t]-1;
        B[t] = B[t]-1;
    }

    for (int t=T-1; t>=0; t--) {
        for (int r=0; r<M; r++) {
            tmp = str[r][A[t]];
            str[r][A[t]] = str[r][B[t]];
            str[r][B[t]] = tmp;
        }
    }

    for (int r=0; r<M; r++) {
        for (int c=0; c<N; c++) {
            printf("%c", str[r][c]);
        }
    }
    printf("\n");

    return 0;
}
