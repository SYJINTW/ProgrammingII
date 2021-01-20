#include"function.h"
void Push(Node** ptr_head, int x) {
    Node* tr = (Node*) malloc(sizeof(Node));
    tr->next = (*ptr_head);
    tr->data = x;
    (*ptr_head) = tr;
}
void Pop(Node** ptr_head) {
    if( *ptr_head == NULL ) return;
	Node* tmp = *ptr_head;
	*ptr_head = (*ptr_head)->next;
	free(tmp);
}
void Reverse_List(Node** ptr_head) {
    if( *ptr_head == NULL ) return;
	Node* tail = NULL, *tmp = NULL;
	Node* head = *ptr_head;
	while( head->next != NULL) {
		tmp = head->next;
		head->next = tail;
		tail = head;
		head = tmp;
	}
	head->next = tail;
	*ptr_head = head; 
}