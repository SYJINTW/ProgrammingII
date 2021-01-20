#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node* next;
} Node;


int main(){
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF)
    {
        Node* head = NULL, *temp = NULL;
        for(int i=0 ; i<N ; ++i){
            int index;
            scanf("%d", &index);
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = index;
            newNode->next = NULL;
            if(i == 0){
                head = newNode;
                temp = head;
                continue;
            }
            temp->next = newNode;
            temp = newNode;
        }
        if(N == 1){
            printf("%d\n", head->data);
            continue;
        }
        temp->next = head;
        // temp = head;
        // while (temp != NULL)
        // {
        //     printf("%d\n", temp->data);
        //     temp = temp->next;
        // }
        Node* curNode = head, *prev = temp;
        while(1){
            for(int j=0 ; j<M-1 ; ++j){
                prev = curNode;
                curNode = curNode->next;
            }
            if(curNode->next == prev){
                printf("%d ", curNode->data);
                printf("%d\n", prev->data);
                break;
            }
            
            printf("%d ", curNode->data);
            prev->next = curNode->next;
            
            free(curNode);
            curNode = prev->next;
        }
        
    }
    return 0;
}