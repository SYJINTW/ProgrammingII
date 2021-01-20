#include <stdio.h>
#include <stdlib.h>
#include "12594.h"
void traversal(Node* head);

int main(){
    int T,M,inst,i;
    int val,idx1,idx2;
    scanf("%d%d", &T,&M);
    Node* head = NULL;
    int *array = (int*)malloc(sizeof(int)*M);
    for(i=0; i<M; ++i){
        scanf("%d",&array[i]);
    }
    if(M > 0){
        head = createList(array, M);
        traversal(head);
    }
    while(T--){
        scanf("%d",&inst);
        if(inst == 0){ // insert
            scanf("%d",&val);
            push_front(&head, val);
        }else if(inst == 1){ // copy link list
            Node* otherHead = copyList(head);
            /* free original list*/
            while(head != NULL){
                Node* temp = head;
                head = head->next;
                free(temp);
            }
            head = otherHead;
        }else if(inst == 2){ // delete element
            scanf("%d",&val);
            deleteElementByIdx(&head, val);
        }else if(inst == 3){ // swap link element
            scanf("%d%d",&idx1, &idx2);
            SwapElementByIdx(&head,idx1,idx2);
        }
        traversal(head);
    }

    /* free linked list*/
    while(head != NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
void traversal(Node* head){
    if(head == NULL)
        return;
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }printf("\n");
}

Node* createList(int *a, int size){
    Node* head = (Node*)malloc(sizeof(Node));
    Node* curNode;
    head->data = a[0];
    curNode = head;
    for(int i=1 ; i<size ; ++i){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = a[i];
        curNode->next = newNode;
        curNode = curNode->next;
    }
    curNode->next = NULL;
    return head;
}

void push_front(Node** head, int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode; 
}

void deleteElementByIdx(Node** head, int idx){
    if(idx == 0){
        Node* curNode = *head;
        *head = (*head)->next;
        free(curNode);
        return;
    }
    Node* prevNode;
    Node* curNode = *head;
    int i=0;
    while(i < idx){
        prevNode = curNode;
        curNode = curNode->next;
        if(curNode == NULL)
            return;
        i++;
    }
    prevNode->next = curNode->next;
    free(curNode);
}

Node* copyList(Node* head){
    Node* newList = (Node*)malloc(sizeof(Node));
    newList->data = head->data;
    Node* curNode = newList;

    Node* oldRef = head;
    oldRef = head->next;

    while(oldRef != NULL){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = oldRef->data;
        curNode->next = newNode;
        curNode = curNode->next;
        oldRef = oldRef->next;
    }
    curNode->next = NULL;
    
    return newList;
}

void SwapElementByIdx(Node** head, int idx1, int idx2){
    Node *Node1, *Node2;
    Node* curNode = *head;

    int i=0;
    while (curNode != NULL)
    {
        if(i == idx1){
            Node1 = curNode;
        }else if(i == idx2){
            Node2 = curNode;
        }
        curNode = curNode->next;
        i++;
    }
    int temp;
    temp = Node1->data;
    Node1->data = Node2->data;
    Node2->data = temp;
}