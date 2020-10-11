#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _NODE
{
	char color[10];
	struct _NODE *next;
} Node;

void insert(Node**, char*, int);

void erase1(Node**, int);

void erase2(Node**, char*);

void reverse(Node**, int, int);

void show(Node **head);

void insert(Node** hp, char* color, int n){
	Node* now = *hp;
	Node* np = (Node*)malloc(sizeof(Node));
	strcpy(np->color, color); //複製 string
	while(n-- && now->next != NULL){
		now = now->next;
	}
	np->next = now->next;
	now->next = np;
}

void erase1(Node** hp, int n){
	Node* now = *hp;
	Node* tmp = NULL;
	//要先判斷 list 會不會是空的，否則會 RTE  
	if(now->next != NULL){
		n--;
		while(n-- && now->next->next != NULL){
			now = now->next;
		}
		tmp = now->next;
		now->next = tmp->next;
		free(tmp);
	}
}

void erase2(Node** hp, char* n){
	Node* now = *hp;
	Node* tmp = NULL;
	while(now != NULL){
		if(now->next != NULL && (!strcmp(now->next->color, n))){
			tmp = now->next;
			now->next = tmp->next;
			free(tmp);
		}
		else now = now->next;
	}
}

void reverse(Node** hp, int a, int b){
	int t = 0;
	Node* now = *hp;
	Node* prev = NULL;
	Node* tmp = NULL;
	//要先判斷 list 會不會是空的，否則會 RTE
	if(now->next != NULL){
		//判斷 a, b 的大小關係
		if(a > b){
			t = a;
			a = b;
			b = t;
		} else;
		b -= a;
		a--;
		//找到 prev 和 now
		while(a-- && now->next != NULL){
			now = now->next;
		}
		prev = now;
		now = now->next;
		//反轉
		while(b-- && now->next != NULL){
			tmp = now->next;
			now->next = tmp->next;
			tmp->next = prev->next;
			prev->next = tmp;
		}
	} else;
}

