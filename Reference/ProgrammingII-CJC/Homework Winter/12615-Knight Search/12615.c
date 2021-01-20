#include <stdlib.h>
#include <stdio.h>

char board[100][100];
char goal[10] = "ICPCASIASG";
int N;
int isFound = 0;

void walk(int a, int b, int current);

int main(){
    scanf("%d", &N);
    char newLine;
    scanf("%c", &newLine);

    for(int i=0 ; i<N ; ++i){
        for(int j=0 ; j<N ; ++j){
            char ch;
            scanf("%c", &ch);
            board[i][j] = ch;
        }
    }
    for(int i=0 ; i<N ; ++i){
        for(int j=0 ; j<N ; ++j){
            if(board[i][j] == 'I'){
                // printf("%d %d\n", i, j);
                walk(i, j, 0);
            }
        }
    }
    // printf("%d\n", isFound);
    printf(isFound ? "YES\n" : "NO\n");

    return 0;
}

void walk(int a, int b, int current){
    if(a < 0 || b < 0 || a >= N || b >= N)
        return;
    if(board[a][b] == goal[current]){
        // printf("%c\n", goal[current]);
        if(current == 9){
            isFound = 1;
            return;
        }else{
            walk(a+1, b+2, current+1);
            walk(a+1, b-2, current+1);
            walk(a-1, b+2, current+1);
            walk(a-1, b-2, current+1);
            walk(a+2, b+1, current+1);
            walk(a+2, b-1, current+1);
            walk(a-2, b+1, current+1);
            walk(a-2, b-1, current+1);
        }    
    }
}