#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1000005

long long a[MAX_SIZE];


int main() {
    int num;
    int N, M, QueryLeft, QueryRight;
    int i,j;
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        long long sum = 0;
        scanf("%d%d", &QueryLeft, &QueryRight);
        for (j = QueryLeft; j <= QueryRight; j++)
        {
			sum += a[j];
		}
        printf("%lld\n", sum);
    }
    return 0;
}
