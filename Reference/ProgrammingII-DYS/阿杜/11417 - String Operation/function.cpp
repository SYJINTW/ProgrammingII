#include<iostream>
#include"function.h"
using namespace std;
Str::Str(char* input){
	int idx = 0;
	if(input[idx]!='\0'){
		Char* temp = new Char(input[idx]);
		head = temp;
		tail = temp;
		idx++;
		while(input[idx]!='\0'){
			Char* new_char = new Char(input[idx]);
			tail->next = new_char;
			tail = tail->next;
			idx++;
		}
	}
}

Str::Str(const Str& copy_str){
	head = new Char(copy_str.head->text);
	tail = head;
	Char* temp = copy_str.head->next;
	while(temp!=NULL){
		Char* new_char = new Char(temp->text);
		tail->next = new_char;
		tail = tail->next;
		temp = temp->next;
	}
}

Str& Str::strInsert(const Str& s){
	Str* temp = new Str(s);
	this->tail->next = temp->head;
	this->tail = temp->tail;
	return *this;
}
