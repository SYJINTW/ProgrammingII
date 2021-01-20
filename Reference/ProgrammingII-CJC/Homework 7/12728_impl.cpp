#include <iostream>
#include "12728.h"

using namespace std;

namespace oj {

// class set_iterator
set_iterator::set_iterator() : _node(nullptr) {}
set_iterator::set_iterator(Node *n) : _node(n) {}
reference set_iterator::operator*() const {return *(_node->p_data); }
iterator_impl_base *set_iterator::clone() const {return new set_iterator(_node); }

bool set_iterator::operator!=(const iterator_impl_base &rhs) const {
    set_iterator d_rhs = dynamic_cast<const set_iterator&>(rhs);
    return (this->_node != d_rhs._node) ? true : false;
}

// class iterator
iterator::iterator(iterator_impl_base *p) : _p(p->clone()){}
reference iterator::operator*() const { return **_p; }
bool iterator::operator!=(const iterator &rhs) const { return *_p != *rhs._p; }

// class set
set::set() {
    root = nullptr;
    infy = new Node(0);
    infy->size = 0;
}

set::~set() {
    clear();
    delete infy;
}

void clearTree(Node* curNode) {
    if(curNode) {
        clearTree(curNode->lc);
        clearTree(curNode->rc);
        delete curNode;
    }
}

void set::clear() {
    clearTree(root);
    root = nullptr;
    infy->size = 0;
}

size_type set::size() const {
    return infy->size;
}
bool set::empty() const {
    return infy->size == 0;
}

iterator set::begin() {
    set_iterator it(this->root);
    return iterator(static_cast<iterator_impl_base*>(&it));
}
iterator set::end() {
    // does not support operator++
    set_iterator it(this->infy);
    return iterator(static_cast<iterator_impl_base*>(&it));
}

void set::insert(const value_type &val) {
    value_type* v = new value_type(val);
    Node* newNode = new Node(v);
    if(root == nullptr) {    
        root = newNode;
        infy->size++;
    } else {
        bool done = false;
        Node* temp = root;
        while(!done) {
            if(*(temp->p_data) > val) {
                if(temp->lc == nullptr) {
                    temp->lc = newNode;
                    done = true;
                    infy->size++;
                } else {
                    temp = temp->lc;
                }
            } else if(*(temp->p_data) < val) {
                if(temp->rc == nullptr) {
                    temp->rc = newNode;
                    done = true;
                    infy->size++;
                } else {
                    temp = temp->rc;
                }
            } else {
                // do nothing 
                done = true; // don't forget this
            }
        }
    }
}

void print(Node* curNode) {
    if(curNode) {
        print(curNode->lc);
        cout << (*(curNode->p_data)) << " ";
        print(curNode->rc);
    }
}

iterator set::lower_bound(const value_type &val) {
    // cout << "current Tree = ";
    // print(root);
    // cout << endl;

    Node* ansNode = nullptr;
    Node* temp = root;
    bool done = false;
    while(!done) {
        if(temp == nullptr){
            done = true;
        } else {
            if(*temp->p_data >= val ) {
                ansNode = temp;
                temp = temp->lc;
            } else {
                temp = temp->rc;
            }
        }
    }
    if(!ansNode) {
        set_iterator it(infy);
        return iterator(static_cast<iterator_impl_base*>(&it));
    } else {
        set_iterator it(ansNode);
        return iterator(static_cast<iterator_impl_base*>(&it));
    }
}

}