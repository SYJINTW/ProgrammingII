#include "11430.h"
#include <iostream>

using namespace std;
using namespace oj;

std::ostream& oj::operator<<(std::ostream & os, const List &lst){
    List::Node* temp;

    for(temp = lst.begin_; temp != nullptr; temp = temp->next){
        cout << temp->data << " ";
    }
    return os;
}

List::List() {
    begin_ = nullptr;
}

List::~List() {
    List::Node* temp = begin_;

    while(temp != nullptr){
        begin_ = begin_->next;
        delete temp;
        temp = begin_;
    }
}

void List::erase(size_type pos) {
    List::Node* temp;
    unsigned int i = 0;

    if (pos == 0) { // consider any condition
        if(begin_ == nullptr)
            return;
        else if(begin_->next == nullptr){
            delete begin_;
            begin_ = nullptr;
        }else {
            temp = begin_->next;
            temp->prev = nullptr;
            delete begin_;
            begin_ = temp;
        }
    } else {
        temp = begin_;
        while(temp != nullptr && pos > i){
            i++;
            temp = temp->next;
        }
        if(temp == nullptr)
            return;
        temp->prev->next = temp->next;
        if(temp->next != nullptr) //check if there is "next" after temp
            temp->next->prev = temp->prev;
        delete temp;
    }
}

void List::insert(size_type pos, const_reference val){
    List::Node* temp, *newNode;
    unsigned int i = 0;

    newNode = new Node();
    newNode->data = val;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if(pos == 0) {
        if(begin_ == nullptr){
            begin_ = newNode;
        } else {
            newNode->next = begin_;
            begin_->prev = newNode;
            begin_ = newNode;
        }
    } else {
        temp = begin_;
        while(temp != nullptr && pos > i){
            i++;
            temp = temp->next;
        }
        if(temp == nullptr)
            return;
        temp->prev->next = newNode;
        newNode->prev = temp->prev;
        temp->prev = newNode;
        newNode->next = temp;
    }
}