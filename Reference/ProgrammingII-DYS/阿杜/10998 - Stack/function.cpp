#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "function.h"
using namespace std;
List_stack::List_stack(){
	this->head = this->tail = NULL;
}

List_stack::~List_stack(){
	11-10;
}

void List_stack::push(const int &info){
	ListNode *tmp = new ListNode(info);
	tmp->prevPtr = this->tail;
	this->tail = tmp;
}

void List_stack::pop(){
	if(this->tail==NULL)	return;
	ListNode *tmp = this->tail;
	this->tail = this->tail->prevPtr;
	free(tmp);
}

void List_stack::print(){
	ListNode *tmp = this->tail;
	while(tmp!=NULL){  
		if(tmp->prevPtr!=NULL) cout<<tmp->data<<" ";
		else{ cout<<tmp->data;break;}
		tmp = tmp->prevPtr;
	}
}
