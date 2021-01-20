#include<stdio.h>

int main(void) {
    int M, N, T, A, B, tmp;
    char str[1000][1000];
    int swap[1000], ori[1000];

    scanf("%d%d%d", &M, &N, &T);
    getchar();

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            scanf("%c", &str[i][j]);
            getchar();
        }
    }

    for (int i=0; i<N; i++) {
        swap[i] = i;
    }

    for (int i=0; i<T; i++) {
        scanf("%d%d", &A, &B);
        tmp = swap[A-1];
        swap[A-1] = swap[B-1];
        swap[B-1] = tmp;
    }

    for (int i=0; i<N; i++) {
        ori[swap[i]] = i;
    }

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            printf("%c", str[i][ori[j]]);
        }
    }
    printf("\n");

    return 0;
}
