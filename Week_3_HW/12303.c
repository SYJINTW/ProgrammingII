#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct t_Node{
	int value;
	struct t_Node* next;
	struct t_Node* prev;	
} Node;

Node *head;
int length = 0;
char buf[10];

void insert(int i, int n){
	Node* np = NULL;
	while(n--){
		np = (Node*)malloc(sizeof(Node));
		if(np != NULL){
			np->next = head->next;
			np->prev = head;
			np->next->prev = np;
			head->next = np;
			np->value = i;
			length++;
		} else;
	}
}

void erase(int n){
	Node* tmp = NULL;
	while(n--){
		tmp = head->next;
		head->next = tmp->next;
		tmp->next->prev = head;
		free(tmp);
		length--;
	}
}

void move(int n){
	Node* now = head;
	if(n >= 0){
		n = n % length;
		while(n--){
			head = head->next;
		}
	}
	else{
		n = -n;
		n = n % length;
		while(n--){
			head = head->prev;
		}
	}	
}

void show(){
	Node* now = head;
	do{
		printf("%d", now->value);
		now = now->next;
		if(now == head) printf("\n");
		else printf(" ");
	} while(now != head);
}

int main(){
	int value, n;
	int a, b;

	scanf("%d%d", &value, &n);
	Node* np = (Node*)malloc(sizeof(Node));
	if(np != NULL){
		np->next = np;
		np->value = value;
		head = np;
		length++;

		while(n--){
			scanf("%s", buf);
			if(!strcmp(buf, "insert")){
				scanf("%d%d", &a, &b);
				insert(a, b);
			}
			else if(!strcmp(buf, "erase")){
				scanf("%d", &a);
				erase(a);
			}
			else if(!strcmp(buf, "move")){
				scanf("%d", &a);
				move(a);
			}
			else if(!strcmp(buf, "show")){
				show();
			}
			else;
		}
	}


}


