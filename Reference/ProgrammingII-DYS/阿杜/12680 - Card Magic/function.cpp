#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
} Node;

Node* ReadOneList(){
	int size;
	int *newData;
	Node* node = (Node*)malloc(sizeof(Node));
	scanf("%d:",&size);
	
	newData = (int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		scanf("%d",&newData[i]);
	}
	node->size = size;
	node->data = newData;
	node->next = NULL;
	return node;
}
void PrintList(Node *curNode){
	while(curNode!=NULL){
		int flag=0;
		if(curNode->size!=-1){
			for(int i=0;i<curNode->size;i++){
				if(flag)
					printf(" %d",*(curNode->data+i));
				else
					printf("%d",curNode->data[i]); 
				flag++;
			}
			printf("\n");
		}
	Node *temp = curNode;
	curNode = curNode->next;
	free(temp->data);
	free(temp);
	}
}
void Merge(Node *head, int from, int to){
	Node *fromNode = head,*toNode = head,*temp = NULL;
	for(int i=0;i<from-1;i++){
		fromNode = fromNode->next;
	}
	temp = fromNode;
	fromNode = fromNode->next;
	
	for(int i=0;i<to;i++){
		toNode = toNode->next;
	}
	
	int i,size = toNode->size + fromNode->size;
	int *mergedata = (int*)malloc(sizeof(int)*size);
	for(i=0;i<toNode->size;i++){
		mergedata[i] = toNode->data[i];
	}
	for(int j=0;j<fromNode->size;j++){
		mergedata[i] = fromNode->data[j];
		i++;
	}
	free(toNode->data);
	free(fromNode->data);
	toNode->data = mergedata;
	toNode->size = size;
	temp->next = fromNode->next;
	free(fromNode);
}
void Cut(Node *head, int from, int left){
	Node *node = (Node*)malloc(sizeof(Node));
	for(int i=0;i<from;i++){
		head = head->next;
	}
	int size = head->size - left;
	int *cutdata = (int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		cutdata[i] = head->data[left+i];
	}
	node->data = cutdata;
	head->size = left;
	node->size = size;
	node->next = head->next;
	head->next = node;
}

#endif
