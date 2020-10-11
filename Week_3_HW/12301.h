#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;
Node *createList(int n);
void freeList(Node* head);
int solveJosephus(Node **head, int step);

Node *createList(int n){
	Node* hp = NULL;
	Node* np = NULL;
	Node* pre = NULL;

	if(n >= 1){
		hp = (Node*)malloc(sizeof(Node));
		hp->number = 1;
		hp->next = hp;
	} else;

	pre = hp;

	for(int i = 2; i <= n; i++){
		np = (Node*)malloc(sizeof(Node));
		np->number = i;
		np->next = hp;
		pre->next = np;
		pre = np;
	}

	return hp;
}

void freeList(Node* head){
	Node* tmp = head;
	while(head == NULL){
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int solveJosephus(Node **head, int step){
	Node* ptr = *head;
	Node* tmp = NULL;
	Node* pre = NULL;
	int n = 0;

	do{
		pre = ptr;
		ptr = ptr->next;
		n++;
	}while(ptr != *head);

	while(n-1){
		for(int i = 0; i < (step-1)%n; i++){
			pre = ptr;
			ptr = ptr->next;
		}
		tmp = ptr;
		ptr = ptr->next;
		pre->next = ptr;
		free(tmp);
		n--;
	}
	return ptr->number;
}


#endif
