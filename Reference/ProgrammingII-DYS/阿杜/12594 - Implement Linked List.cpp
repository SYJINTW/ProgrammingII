#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* createList(int *a, int size){
    Node *head, *new, *next = NULL;
    for(int i=size-1; i>=0; i--){
        new = malloc(sizeof(Node));
        new->data = a[i];
        new->next = next;
        next = new;
    }
    head = new;
    return head;
}

void push_front(Node** head, int val){
    Node *new = malloc(sizeof(Node));
    new->data = val;
    new->next = *head;
    *head = new;
}

Node* copyList(Node* head){
    Node *cur;
    Node *copy_head, *copy_pre;
    Node *new;

    if(head == NULL)
        return copy_head = NULL;
    
    copy_head = malloc(sizeof(Node));
    copy_head->data = head->data;
    copy_head->next = NULL;
    copy_pre = copy_head;
    cur = head->next;
    while(cur != NULL){
        new = malloc(sizeof(Node));
        new->data = cur->data;
        new->next = NULL;
        copy_pre->next = new;
        copy_pre = new;
        cur = cur->next;
    }
    return copy_head;
}

void deleteElementByIdx(Node** head, int idx){
    int i;
    Node *cur, *pre;

    if(idx == 0){
        cur = *head;
        *head = (*head)->next;
        free(cur);
    }

    pre = *head;
    cur = (*head)->next;
    i = 1;
    while(cur != NULL){
        if(i == idx){
            pre->next = cur->next;
            free(cur);
            break;
        }
        pre = cur;
        cur = cur->next;
        i++;
    }
}

void SwapElementByIdx(Node** head, int idx1, int idx2){
    int i;
    Node *cur, *pre, *tmp, *new_head;
    Node *pre1 = NULL, *pre2 = NULL;

    if(idx1 == idx2)
        return ;

    if(idx1 > idx2){int tmp=idx1; idx1=idx2; idx2=tmp;}
    if(idx1 == 0){
        pre1 = NULL;
    }

    pre = *head;
    cur = (*head)->next;
    i = 1;
    while(cur != NULL){
        if(i == idx1){
            pre1 = pre;
        }
        if(i == idx2){
            pre2 = pre;
        }
        pre = cur;
        cur = cur->next;
        i++;
    }

    if(pre2 == NULL)
        return;
    if(pre1 == NULL){
        new_head = pre2->next;
        tmp = (*head)->next;
        (*head)->next = pre2->next->next;
        pre2->next->next = tmp;
        pre2->next = *head;
        *head = new_head;
    }
    else {
        tmp = pre1->next->next;
        pre1->next->next = pre2->next->next;
        pre2->next->next = tmp;
        tmp = pre1->next;
        pre1->next = pre2->next;
        pre2->next = tmp;
    }
}
