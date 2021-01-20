#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[10][10];
int N, M;
int size;

void initBoard(){
    for(int i=0 ; i<size ; ++i)
        for(int j=0 ; j<size ; ++j)
            board[i][j] = '0';
}

bool checkQueen(int r, int c){
    for(int i=0 ; i<=r ; ++i){
        if(c-i >= 0 && board[r-i][c-i] != '0')
            return false;
        if(c+i < size && board[r-i][c+i] != '0')
            return false;
        if(board[r-i][c] != '0')
            return false;
    }
    return true;
}

bool checkRook(int r, int c){
    for(int i=0 ; i<=r ; ++i){
        if(c-i >= 0 && board[r-i][c-i] == 'Q')
            return false;
        if(c+i < size && board[r-i][c+i] == 'Q')
            return false;
        if(board[r-i][c] != '0')
            return false;
    }
    return true;
}

int putChess(int r, int n, int m){
    if(r == size)
        return 1;

    int count = 0;

    for(int c=0 ; c<size ; ++c){
        if(n<N && checkQueen(r, c)){
            board[r][c] = 'Q';
            count += putChess(r+1, n+1, m);
            board[r][c] = '0';
        }
        if(m<M && checkRook(r, c)){
            board[r][c] = 'R';
            count += putChess(r+1, n, m+1);
            board[r][c] = '0';
        }
    }

    return count;
}


int main(){ 
    while(scanf("%d %d", &N, &M) != EOF){
        size = N+M;
        initBoard();
        printf("%d\n", putChess(0, 0, 0));
    }
    return 0;
}