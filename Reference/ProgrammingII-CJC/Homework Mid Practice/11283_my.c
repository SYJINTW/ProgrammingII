#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node *next;
} Node;

int main(){
    Node *head = NULL, *prev = NULL;

    int num;
    while(scanf("%d", &num)){
        if(num == -1){
            break;
        }
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = NULL;
        if(!head){
            head = newNode;
            prev = head;
        }else{
            prev->next = newNode;
            prev = prev->next;
        }
    }
    Node *tail = prev;
    tail->next = head;
    // Node* curNode = head;
    // while(curNode){
    //     printf("%d ", curNode->data);
    //     curNode = curNode->next;
    // }
    int k;
    scanf("%d", &k);

    Node* curNode = head;
    prev = NULL;
    while(k--){
        prev = curNode;
        curNode = curNode->next;
    }
    head = curNode;
    prev->next = NULL;

    curNode = head;
    while(curNode){
        printf("%d ", curNode->data);
        curNode = curNode->next;
    }


    return 0;
}