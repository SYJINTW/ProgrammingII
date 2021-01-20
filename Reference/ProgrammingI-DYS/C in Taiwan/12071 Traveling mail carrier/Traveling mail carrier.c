#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n, visited_c, distance;
int matrix[10][10];
int visited[10];
int MIN = INT_MAX;

int dfs(int cur) {
    if (visited_c == n) {
        // All visited.
        if (distance + matrix[cur][0] < MIN)
            MIN = distance + matrix[cur][0];
    }
    for (int j = 0; j < n; j++) {
        if (!visited[j]) {
            visited[j] = 1;
            visited_c++;
            distance += matrix[cur][j];
            dfs(j);
            visited[j] = 0;
            visited_c--;
            distance -= matrix[cur][j];
        }
    }
}

int main(void) {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
    	visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    visited[0] = 1;
    visited_c = 1;
    distance = 0;
    dfs(0);
    printf("%d\n", MIN);
    return 0;
}
