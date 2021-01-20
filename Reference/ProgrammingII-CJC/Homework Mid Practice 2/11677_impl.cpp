#include "11677.h"
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

void List::remove(const_reference val) {
    Node* temp = begin_;
    
    if(temp == nullptr)
        return;

    while(temp != nullptr) {
        if(temp->data == val) {
            Node* nextNode = temp->next;

            if(temp == begin_) { //head
                if(temp->next != nullptr) { 
                    temp->next->prev = nullptr;
                    begin_ = nextNode;
                } else { // only one node
                    begin_ = nextNode; // (null)
                }
            } else if (temp->next == nullptr) { //tail
                temp->prev->next = nullptr;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
}

std::ostream& oj::operator<<(std::ostream & os, const List & list) {
    List::Node* temp;

    for(temp = list.begin_; temp != nullptr; temp = temp->next){
        cout << temp->data << " ";
    }

    return os;
}