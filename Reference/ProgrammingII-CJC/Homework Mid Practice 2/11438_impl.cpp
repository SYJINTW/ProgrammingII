#include "11438.h"
#include <iostream>

using namespace std;
using namespace oj;

List::List() {
    begin_ = nullptr;
}

List::~List() {
    Node* temp = begin_;

    while(temp != nullptr){
        begin_ = begin_->next;
        delete temp;
        temp = begin_;
    }
}

void List::pop_back() {
    Node* temp = begin_;

    if(temp == nullptr) {
        return;
    } else if (temp->next == nullptr) {
        delete temp;
        begin_ = nullptr;
    } else {
        while(temp->next != nullptr ) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }
}

void List::push_back(const_reference val) {
    Node* temp = begin_;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if(temp == nullptr) {
        begin_ = newNode;
        return;
    }

    while(temp->next != nullptr) {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

std::ostream& oj::operator<<(std::ostream & os, const List & list) {
    List::Node* temp;

    for(temp = list.begin_; temp != nullptr; temp = temp->next){
        cout << temp->data << " ";
    }

    return os;
}