#include <stdio.h>
#include <stdlib.h>
#include "11270.h"


Node* createList(){
	Node* head = NULL;
	Node* temp = NULL;

	int data;
	while(1){
		scanf("%d", &data);
		if(data == -1)
			break;
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = NULL;
		if(head == NULL){
			head = newNode;
			temp = head;
		}else{
			temp->next = newNode;
			temp = temp->next;
		}
	}
	temp->next = NULL;

	return head;
}

Node* reverse(Node* head){
	Node* newHead = NULL;

	Node *curNode = head, *prev = NULL, *nextNode = NULL;
	
	prev = curNode;
	curNode = curNode->next;
	nextNode = curNode->next;

	head->next = NULL;

	while (nextNode != NULL)
	{
		curNode->next = prev;

		prev = curNode;
		curNode = nextNode;
		nextNode = nextNode->next;
	}
	curNode->next = prev;
	newHead = curNode;

	return newHead;
}
