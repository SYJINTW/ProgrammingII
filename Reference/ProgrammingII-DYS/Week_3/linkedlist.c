#include<stdio.h>
#include<stdlib.h>

typedef struct t_Node{
	int data;
	struct t_Node* next;
}Node;

void insert_increase_list(Node**, int);
void showList(Node**);
void delete_node(Node**, int);


int main(){
	Node* head = NULL;
	//insert
	insert_increase_list(&head, 2);
	showList(&head);
	insert_increase_list(&head, 4);
	showList(&head);
	insert_increase_list(&head, 1);
	showList(&head);
	insert_increase_list(&head, 3);
	showList(&head);
	//delete
	delete_node(&head, 4); //others
	showList(&head);
	delete_node(&head, 1); //head
	showList(&head);
	delete_node(&head, 100); //不存在
	showList(&head);
}

void insert_increase_list(Node* *hp, int data){
	Node* local_head = *hp;	//建立一個 local_head 等於外面的 head
	//hp: &head  *hp: head --> local_head = head
	
	Node* ptr = local_head;
	Node* pre = NULL;
	while(ptr != NULL){
		if(data <= ptr->data){
			break;
		} else
		pre = ptr; //remember the previous
		ptr = ptr->next;
		
	}
	
	Node* cur = (Node*)malloc(sizeof(Node));
	cur->data = data;
	cur->next = ptr;

	if(pre == NULL)	//第一次就找到
		local_head = cur;
	else
		pre->next = cur;

	*hp = local_head;	//更改外部的 head
   	//*hp: head --> head = local_head
}


void showList(Node* *hp){
	Node* ptr = *hp;
	while(ptr != NULL){
		printf("(%d)-->", ptr->data);
		ptr = ptr->next;
	}
	printf("///\n");
}

void delete_node(Node** hpp, int data){
	Node* local_head = *hpp;
	Node *p, *pre;
	pre = NULL;
	p = local_head;
	while(p != NULL){
		if(p->data == data) break;
		else{
			pre = p;
			p = p->next;
		}
	}
	if(p != NULL){
		if(pre == NULL){
			*hpp = p->next;
			free(p);
		}
		else{
			pre->next = p->next;
			free(p);
		}
	} else;
}


