#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    char taken;
    int height;
    int left;
    int right;
}Node;

Node* lolis;
int* sortedId;

int compareNode(const void *a, const void *b);

int main(){
    int N, K;
    scanf("%d %d", &N, &K);

    lolis = (Node*) malloc(N * sizeof(Node));
    sortedId = (int *)malloc(N * sizeof(int));

    for(int i=0 ; i<N ; ++i){
        int height;
        scanf("%d", &height);

        lolis[i].taken = 0;
        lolis[i].height = height;
        lolis[i].right = i+1;
        lolis[i].left = i-1;

        sortedId[i] = i;
    }
    lolis[N-1].right = -1;

    qsort(sortedId, N, sizeof(int), compareNode);
    
    int remain = N;
    char turn = 'S';
    int head = 0, center, left, right;
    while(remain > 0){
        while(lolis[sortedId[head]].taken)
            head++;
        
        center = sortedId[head];
        lolis[center].taken = turn;
        remain--;

        left = lolis[center].left;
        right = lolis[center].right;
        for(int i=0 ; i<K ; ++i){
            if(left >= 0){
                lolis[left].taken = turn;
                remain--;
                left = lolis[left].left;
            }
            if(right >= 0){
                lolis[right].taken = turn;
                remain--;
                right = lolis[right].right;
            }
        }

        if(right >= 0){
            lolis[right].left = left;
        }

        if(left >= 0){
            lolis[left].right = right;
        }

        turn = (turn == 'S') ? 'J' : 'S';
    }

    for(int i=0 ; i<N ; ++i){
        printf("%c", lolis[i].taken);
    }
    printf("\n");

    return 0;
}

int compareNode(const void *a, const void *b){
    int idx1 = * (int *)a;
    int idx2 = * (int *)b;
    if(lolis[idx1].height > lolis[idx2].height){
        return -1;
    }
    else return 1;
}