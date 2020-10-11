#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* createList(int *a, int size){
	int k;
	Node* np = NULL;
	Node* tmp = NULL;
	Node* hp = (Node*)malloc(sizeof(Node));
	hp->data = a[0];
	hp->next = NULL;
	for(int i = 0; i < size; i++){
		tmp = (Node*)malloc(sizeof(Node));
		tmp->data = a[i];
		tmp->next = NULL;
		if(i == 0){
			hp = tmp;
		}
		else{
			np->next = tmp;
			tmp->next = NULL;
			tmp->data = a[i];	
		}
		np = tmp;
	}
	return hp;
}

void push_front(Node** head, int val){
	Node* hp = *head;
	Node* np = (Node*)malloc(sizeof(Node));
	np->data = val;
	np->next = hp;
	*head = np;
}

void deleteElementByIdx(Node** head, int idx){
	Node* now = *head;
	Node* prev = NULL;
	Node* tmp = NULL;
	while(idx-- && now != NULL){
		prev = now;
		now = now->next;
	}
	if(now == *head){
		tmp = now;
		now = now->next;
		free(tmp);
		*head = now;
	}
	else if(now != NULL){
		tmp = now;
		now = now->next;
		prev->next = now;
		free(tmp);
	} else;
}

Node* copyList(Node* head){
	Node* now = head;
	Node* tmp = NULL;
	Node* np = NULL;
	Node* hp = NULL;
	while(now != NULL){
		tmp = (Node*)malloc(sizeof(Node));
		if(now == head) hp = tmp;
		else np->next = tmp;
		np = tmp;
		np->next = NULL;
		np->data = now->data;
		now = now->next;
	}
	return hp;
}

void SwapElementByIdx(Node** head, int idx1, int idx2){
	Node* hp = *head;
	Node* prev1 = NULL;
	Node* prev2 = NULL;
	Node* tmp1 = NULL;
	Node* tmp2 = NULL;
	Node* tmp = NULL;
	Node* now = hp;
	//find max(idx1, idx2)
	if(idx1 > idx2){
		int temp = idx2;
		idx2 = idx1;
		idx1 = temp;
	} else;
	//find idx1
	while(idx1-- && now != NULL){
		prev1 = now;
		now = now->next;
		idx2--;
	}
	tmp1 = now;
	//check if out of index
	if(tmp1 != NULL){
		//find idx2
		while(idx2-- && now != NULL){
			prev2 = now;
			now = now->next;
		}
		tmp2 = now;
		//check if out of index
		if(tmp2 != NULL){
			if(hp == tmp1) hp = tmp2;
			else prev1->next = tmp2;;
			//swap
			prev2->next = tmp1;
			tmp = tmp2->next;
			tmp2->next = tmp1->next;
			tmp1->next = tmp;
		} else;
	} else;
	*head = hp;
}
