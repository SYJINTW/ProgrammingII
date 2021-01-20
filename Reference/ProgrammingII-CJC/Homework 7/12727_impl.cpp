#include <iostream>
#include "12727.h"

using namespace std;

namespace oj {

// class list_iterator
iterator_impl_base& list_iterator::operator++() { // prefix increment
    this->_node = this->_node->next;
    return *this;
}

bool list_iterator::operator!=(const iterator_impl_base &rhs) const {
    list_iterator d_rhs = dynamic_cast<const list_iterator&>(rhs);
    return (this->_node != d_rhs._node) ? true : false;
}

// class list
ptrdiff_t baseOffset() {
    Node* basePtr = new Node(0);
    value_type* elemPtr = &(basePtr->data);
    // ptrdiff_t offset = (ptrdiff_t)elemPtr - (ptrdiff_t)basePtr;
    ptrdiff_t offset = reinterpret_cast<ptrdiff_t>(elemPtr) - reinterpret_cast<ptrdiff_t>(basePtr);

    delete basePtr;
    return offset;
}

Node* iter_to_node(iterator it) {
    // Node* node = (Node* )((ptrdiff_t)&(*it) - baseOffset());
    Node* node = reinterpret_cast<Node*>(reinterpret_cast<ptrdiff_t>(&(*it)) - baseOffset());
    return node;
} 

list::list() {
    _head = new Node(0); //dummy node, which represents _tail
    _head->next = nullptr;
    _head->prev = nullptr;
    _tail = _head;
    _size = 0;
}

list::~list() {
    clear();
    delete _tail;
}

void list::clear() {
    Node* temp = _head;
    while(temp != _tail) {
        Node* curNode = temp;
        temp = temp->next;
        delete curNode;
    }
    _head = _tail;
    _size = 0;
}

size_type list::size() const {
    return _size;
}

bool list::empty() const {
    return _size == 0;
}

iterator list::begin() {
    list_iterator it(this->_head);
    return iterator(static_cast<iterator_impl_base*>(&it)); // when you sure this will be ok
    // return iterator(dynamic_cast<iterator_impl_base*>(&it));
}

iterator list::end() {
    list_iterator it(this->_tail);
    return iterator(static_cast<iterator_impl_base*>(&it)); // when you sure this will be ok
    // return iterator(dynamic_cast<iterator_impl_base*>(&it));
}

void list::insert(iterator it, size_type size, const value_type val) {
    Node* targetNode = iter_to_node(it);

    for(int i=0; i<size; ++i) {
        Node* newNode = new Node(val);
        newNode->prev = targetNode->prev;
        newNode->next = targetNode;
        if(targetNode->prev)
            targetNode->prev->next = newNode;
        targetNode->prev = newNode;
        if(targetNode == _head){
            if(i == 0) {
                _head = newNode;
            }
        }
    }
    
    _size += size;
}
void list::erase(iterator it_begin, iterator it_end) {
    Node* curNode = iter_to_node(it_begin);
    Node* lastNode = iter_to_node(it_end);

    while(curNode != lastNode) {
        if(curNode->prev)
            curNode->prev->next = curNode->next;
        if(curNode->next)
            curNode->next->prev = curNode->prev;
        Node* temp = curNode;
        if(curNode == _head) {
            _head = curNode->next;
        }
        curNode = curNode->next;
        delete temp;
        _size--;
    }
}

}; 