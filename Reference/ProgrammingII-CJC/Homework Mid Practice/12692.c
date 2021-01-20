#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int id;
    // bool visited;
    struct _Node *next;
} Node;

Node* edges[200001];
Node* tails[200001];

int val_root;
bool visited[200001];

void DFS(int id, int level);

int main(){
    int N, S;
    scanf("%d %d", &N, &S);

    for(int i=0 ; i<N-1 ; ++i){
        int u, v;
        scanf("%d %d", &u, &v);

        Node* newU = (Node*) malloc(sizeof(Node));
        newU->id = u;
        // newU->visited = false;
        newU->next = NULL;

        if(!edges[v]){
            edges[v] = newU;
            tails[v] = newU;
        }else{
            tails[v]->next = newU;
            tails[v] = tails[v]->next;
        }


        Node* newV = (Node*) malloc(sizeof(Node));
        newV->id = v;
        // newV->visited = false;
        newV->next = NULL;

        if(!edges[u]){
            edges[u] = newV;
            tails[u] = newV;
        }else{
            tails[u]->next = newV;
            tails[u] = tails[u]->next;
        }
    }
    // Node* temp = edges[1];
    // while(temp){
    //     printf("%d ", temp->id);
    //     temp = temp->next;
    // }
    DFS(S, 0);

    printf("%d\n", val_root);

    return 0;
}

void DFS(int id, int level){
    visited[id] = true;
    val_root += level;
    Node* temp = edges[id];
    while(temp){
        if(!visited[temp->id]){
            DFS(temp->id, level+1);
        }
        temp = temp->next;
    }
}