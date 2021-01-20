#include "../header/I2P2_List.h"
// #include <iostream>

namespace I2P2
{
    /* Your definition for the List class goes here */
    List::~List() {
        clear();
        delete _head;
    }
    List::List() {
        _head = new Node(0); // dummy node, which represents _tail
        _head->next = _head; // not nullptr
        _head->prev = _head; // not nullptr
        _size = 0;
    }
    List::List(const List &rhs) : List() { //靠邀阿忘記初始化= =
        Node* temp = rhs._head->next;
        while(temp != rhs._head) {
            push_back(temp->data);
            temp = temp->next;
        }
    }
    List &List::operator=(const List &rhs) {
        if(this != &rhs) {
            this->~List();
            new (this) List(rhs);
        }
        return *this;
    }
    iterator List::begin() {
        // std::cout << "begin ";
        // std::cout << "this->head->data = " << this->_head->data << "\n";

        list_iterator it(this->_head->next, this->_head);
        return iterator(static_cast<iterator_impl_base*>(&it));
    }
    const_iterator List::begin() const {
        // std::cout << "cbegin\n";
        list_iterator it(this->_head->next, this->_head);
        return const_iterator(static_cast<iterator_impl_base*>(&it));
    }
    iterator List::end() {
        // std::cout << "end ";
        // std::cout << "this->head->data = " << this->_head->data << "\n";

        list_iterator it(this->_head, this->_head);
        return iterator(static_cast<iterator_impl_base*>(&it));
    }
    const_iterator List::end() const {
        // std::cout << "cend\n";
        list_iterator it(this->_head, this->_head);
        return const_iterator(static_cast<iterator_impl_base*>(&it));
    }
    reference List::front() {
        // std::cout << "front\n";
        return _head->next->data;
    }
    const_reference List::front() const {
        // std::cout << "front\n";
        return _head->next->data;
    }
    reference List::back() {
        // std::cout << "back\n";
        return _head->prev->data;
    }
    const_reference List::back() const {
        // std::cout << "back\n";
        return _head->prev->data;
    }
    size_type List::size() const {
        return _size;
    }

    void List::clear() {
        Node* curNode = _head->next;
        while(curNode != _head) {
            Node* temp = curNode;
            curNode = curNode->next;
            delete temp;
        }
        _head->next = _head;
        _head->prev = _head;
        _size = 0;
    }

    bool List::empty() const {
        return _size == 0;
    }
    void List::erase(const_iterator pos) {
        Node* targetNode = pos.node_ref();
        targetNode->prev->next = targetNode->next;
        targetNode->next->prev = targetNode->prev;
        delete targetNode;
        _size--;
    }
    void List::erase(const_iterator begin, const_iterator end) {

        Node* curNode = begin.node_ref();
        Node* endNode = end.node_ref();

        while(curNode != endNode) {
            curNode->prev->next = curNode->next;
            curNode->next->prev = curNode->prev;
            Node* temp = curNode;
            curNode = curNode->next;
            _size--;
            delete temp;
        }
        // const_iterator it = begin;
        // while(it != end) {
        //     erase(it);
        // }
    }
    void List::insert(const_iterator pos, size_type count, const_reference val) {
        Node* targetNode = pos.node_ref();

        for(int i=0; i<count; ++i) {
            Node* newNode = new Node(val);
            newNode->prev = targetNode->prev;
            newNode->next = targetNode;
            targetNode->prev->next = newNode;
            targetNode->prev = newNode;
        }
        
        _size += count;
    }
    void List::insert(const_iterator pos, const_iterator begin, const_iterator end) {
        Node* targetNode = pos.node_ref();
        
        // const_iterator may be (vector_iterator)
        while(begin != end) {
            Node* newNode = new Node(*begin);
            newNode->prev = targetNode->prev;
            newNode->next = targetNode;
            targetNode->prev->next = newNode;
            targetNode->prev = newNode;
            _size++;
            begin++;
        }
    }
    void List::pop_back() {
        Node* curNode = _head->prev;
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        delete curNode;
        _size--;
    }
    void List::pop_front() {
        Node* curNode = _head->next;
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        delete curNode;
        _size--;
    }
    void List::push_back(const_reference val) {
        Node* newNode = new Node(val);
        newNode->prev = _head->prev;
        newNode->next = _head;
        _head->prev->next = newNode;
        _head->prev = newNode;
        _size++;
    }
    void List::push_front(const_reference val) {
        Node* newNode = new Node(val);
        newNode->prev = _head;
        newNode->next = _head->next;
        _head->next->prev = newNode;
        _head->next = newNode;
        _size++;
    }
} // namespace I2P2
