#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define ll long long int
#define next ptr_to_next_node
#define prev ptr_to_prev_node
#define ch character

typedef struct _NODE
{
	char character;
	struct _NODE *ptr_to_next_node;
	struct _NODE *ptr_to_prev_node;
} Node;

Node *head, *tail;

void insert(Node** cursor, char a){
	Node* cur = *cursor;
	Node* np = (Node*)malloc(sizeof(Node));
	// list 是空的
	if(cur == tail){
		tail = np;
	} else;
	np->ch = a;

	np->prev = cur;
	np->next = cur->next;
	np->next->prev = np;
	cur->next = np;

	*cursor = cur;
}

void deletion(Node** cursor){
	Node* cur = *cursor;
	Node* tmp = NULL;
	// cursor don't reach the end
	if(cur != tail){
		if(cur->next == tail) tail = cur;
		else;
		tmp = cur->next;
		cur->next = tmp->next;
		cur->next->prev = cur;
		free(tmp);
	} else;
}

void backspace(Node** cursor){
	Node* cur = *cursor;
	Node* tmp = NULL;
	if(cur != head){
		if(cur == tail){
			tail = cur->prev;
		} else;
		tmp = cur;
		cur = cur->prev;
		cur->next = tmp->next;
		cur->next->prev = cur;
		free(tmp);
		*cursor = cur;
	} else;
}

void go_left(Node** cursor, int n){
	Node* cur = *cursor;
	while(n--){
		cur = cur->prev;
	}
	*cursor = cur;
}

void go_right(Node** cursor, int n){
	Node* cur = *cursor;
	while(n--){
		cur = cur->next;
	}
	*cursor = cur;
}

void go_home(Node** cursor){
	*cursor = head;
}

void go_end(Node** cursor){
	*cursor = tail;
}

void show();
