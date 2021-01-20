#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))

int ch[505][505];
int a[505][505];
int is1[505][505], is2[505][505];
int N, M;
int start_i, start_j;
int end_i, end_j;

int gx[] = {0, 1, 0, -1, 0};
int gy[] = {1, 0, -1, 0, 0};

void DFS(int x, int y, int k);

int main(){
    scanf("%d %d", &N, &M);
    scanf("%d %d", &start_i, &start_j);
    scanf("%d %d", &end_i, &end_j);
    
    start_i--; start_j--; end_i--; end_j--;
    for(int i=0 ; i<N ; ++i){
        getchar();
        for(int j=0 ; j<M ; ++j){
            char c;
            scanf("%c", &c);
            ch[i][j] = c - '0';
        }
    }

    DFS(start_i, start_j, 1);
    DFS(end_i, end_j, 2);

    if(a[end_i][end_j] == 1){ //被第一個DFS改成1，因為有值了就不會被改成2
        printf("0\n");
        return 0;
    }

    for(int i=0 ; i<N ; ++i){
        for(int j=0 ; j<M ; ++j){
            for(int k=0 ; k<5 ; ++k){
                int x = i+gx[k], y = j+gy[k];
                if(x >= 0 && x < N && y >= 0 && y < M){
                    if(a[x][y] == 1)
                        is1[i][j] = 1;
                    if(a[x][y] == 2)
                        is2[i][j] = 1;
                }
            }
        }
    }
    
    int ans = INT_MAX;
    for(int i=0 ; i<N ; ++i){
        for(int j=0 ; j<M ; ++j){
            for(int k=0 ; k<N-i ; ++k){//只需要會向右，向下搭建就好
                if( (is1[i+k][j] && is2[i][j]) || (is1[i][j] && is2[i+k][j]) )
                    ans = min(ans, k+1);
            }
            for(int k=0 ; k<M-j ; ++k){
                if( (is1[i][j+k] && is2[i][j]) || (is1[i][j] && is2[i][j+k]) )
                    ans = min(ans, k+1);
            }
        }
    }

    ans = (ans == INT_MAX) ? -1 : ans;
    printf("%d\n", ans);

    return 0;
}

void DFS(int x, int y, int k){
    if(x < 0 || x >= N || y < 0 || y >= M || a[x][y] != 0 || ch[x][y] != 1)
        return;
    
    a[x][y] = k;
    for(int i=0 ; i<4 ; ++i){
        DFS(x+gx[i], y+gy[i], k);
    }
}