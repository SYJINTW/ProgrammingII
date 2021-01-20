#include<iostream>
#include<string>
#include<string>
#include"function.h"
using namespace std;
using namespace oj;


List::List(){
    begin_ = nullptr;
}

List::~List(){
    List::Node* tmp = begin_;

    while(tmp!=nullptr){
        // your code here
    }
}

void List::erase(size_type pos){
    unsigned int i;
    Node* tmp;

    if (pos==0){
        // your code here
    } else {
        // your code here
    }
}

void List::insert(size_type pos, const_reference val){
    unsigned int i;
    Node* tmp, *newNode;

    newNode = new Node();
    newNode->data = val;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (pos==0){
        // your code here
    } else {
        // your code here
    }
}

std::ostream& oj::operator<<(std::ostream &os, const List &lst){
    List::Node* tmp;

    for(tmp=lst.begin_; tmp!=nullptr; tmp=tmp->next){
        os << tmp->data<<' ';
    }
    return os;
}
