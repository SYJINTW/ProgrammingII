#include <stdio.h>
int visited[12];
int arr[12];

int main()
{
    for(int i=1; i<=9; i++) {
        scanf("%d", &arr[i]);
    }

    int now = 1;
    int sum = 0;
    while(visited[now] != 1) {
        visited[now] = 1;
        sum += arr[now];
        now = arr[now];
    }
    printf("%d\n", sum);

    return 0;
}

// By tangerine1202
