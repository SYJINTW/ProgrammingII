#include "../header/I2P2_iterator.h"
#include <iostream>

namespace I2P2
{
    /* Your definition for the iterator class goes here */

    //////////////////////////////////////
    //                                  //
    //			const_iterator          //
    //                                  //
    //////////////////////////////////////
    // destructor
    const_iterator::~const_iterator() {
        delete p_;
        p_ = nullptr;
    }
    // default constructor
    const_iterator::const_iterator() {
        p_ = nullptr;
    }
    // copy constructor
    const_iterator::const_iterator(const const_iterator &rhs) : p_(rhs.p_->clone()) {}
    // constructor
    const_iterator::const_iterator(iterator_impl_base *p) : p_(p->clone()) {}
    
    // operators
    // operator = 
    const_iterator &const_iterator::operator=(const const_iterator &rhs) {
        // maybe?
        p_ = rhs.p_->clone();
        return *this;
    }
    // operator ++x
    const_iterator &const_iterator::operator++() {
        ++*p_;
        return *this;
    }
    // operator x++
    const_iterator const_iterator::operator++(int val) {
        const_iterator it(p_);
        ++*p_;
        return it;
    }
    // operator --x
    const_iterator &const_iterator::operator--() {
        --*p_;
        return *this;
    }
    // operator x--
    const_iterator const_iterator::operator--(int) {
        const_iterator it(p_);
        --*p_;
        return it;
    }
    // operator +=
    const_iterator &const_iterator::operator+=(difference_type offset) {
        while(offset--) {
            ++*p_;
        }
        return *this;
    }
    // operator +
    const_iterator const_iterator::operator+(difference_type offset) const {
        const_iterator it(p_);
        while(offset--) {
            ++it;
        }
        return it;
    }
    // operator -=
    const_iterator &const_iterator::operator-=(difference_type offset) {
        while(offset--) {
            --*p_;
        }
        return *this;
    }
    // operator -
    const_iterator const_iterator::operator-(difference_type offset) const {
        const_iterator it(p_);
        while(offset--) {
            --it;
        }
        return it;
    }
    // operator - (return std::ptrdiff_t)
    const_iterator::difference_type const_iterator::operator-(const const_iterator &rhs) const {
        return *p_ - *(rhs.p_);
    }
    // operator ->
    const_iterator::pointer const_iterator::operator->() const {
        return (*p_).operator->();
    }
    // operator *
    const_iterator::reference const_iterator::operator*() const {
        return *(*p_);
    }
    // operator []
    const_iterator::reference const_iterator::operator[](difference_type offset) const {
        return (*p_)[offset];
    }
    // operator compare // only const_iterator
    bool const_iterator::operator==(const const_iterator &rhs) const {
        return (*p_) == *(rhs.p_);
    }
    bool const_iterator::operator!=(const const_iterator &rhs) const {
        return (*p_) != *(rhs.p_);
    }
    bool const_iterator::operator<(const const_iterator &rhs) const {
        return (*p_) < *(rhs.p_);
    }
    bool const_iterator::operator>(const const_iterator &rhs) const {
        return (*p_) > *(rhs.p_);
    }
    bool const_iterator::operator<=(const const_iterator &rhs) const {
        return (*p_) <= *(rhs.p_);
    }
    bool const_iterator::operator>=(const const_iterator &rhs) const {
        return (*p_) >= *(rhs.p_);
    }

    // my functions
    Node* const_iterator::node_ref() const {
        return p_->node_ref();
    }
    
    //////////////////////////////////////
    //                                  //
    //			iterator                //
    //                                  //
    //////////////////////////////////////
    iterator::iterator() {
        p_ = nullptr;
    }
    iterator::iterator(iterator_impl_base *p) {
        this->p_ = p->clone();
    }
    iterator::iterator(const iterator &rhs) {
        this->p_ = rhs.p_->clone();
    }
    iterator &iterator::operator++() {
        ++*p_;
        return *this;
    }
    iterator iterator::operator++(int) {
        iterator it(p_);
        ++*p_;
        return it;
    }
    iterator &iterator::operator--() {
        --*p_;
        return *this;
    }
    iterator iterator::operator--(int) {
        iterator it(p_);
        --*p_;
        return it;
    }
    iterator &iterator::operator+=(difference_type offset) {
        while(offset--) {
            ++*p_;
        }
        return *this;
    }
    iterator iterator::operator+(difference_type offset) const {
        iterator it(p_);
        while(offset--) {
            ++it;
        }
        return it;
    }
    iterator &iterator::operator-=(difference_type offset) {
        while(offset--) {
            --*p_;
        }
        return *this;
    }
    iterator iterator::operator-(difference_type offset) const {
        iterator it(p_);
        while(offset--) {
            --it;
        }
        return it;
    }
    iterator::difference_type iterator::operator-(const iterator &rhs) const {
        return *p_ - *(rhs.p_);
    }
    iterator::pointer iterator::operator->() const {
        return (*p_).operator->();
    }
    iterator::reference iterator::operator*() const {
        return *(*p_);
    }
    iterator::reference iterator::operator[](difference_type offset) const {
        return (*p_)[offset];
    }

    // my functions
    Node* iterator::node_ref() const {
        return p_->node_ref();
    }

    //////////////////////////////////////
    //                                  //
    //			vector_iterator         //
    //                                  //
    //////////////////////////////////////
    vector_iterator::vector_iterator() : ptr_to_data(nullptr) {}
    iterator_impl_base &vector_iterator::operator++() {
        ++ptr_to_data;
        return *this;
    }
    iterator_impl_base &vector_iterator::operator--() {
        --ptr_to_data;
        return *this;
    }
    iterator_impl_base &vector_iterator::operator+=(difference_type offset) {
        // while(offset--) {
        //     ++ptr_to_data;
        // }
        ptr_to_data += offset;
        return *this;
    }
    iterator_impl_base &vector_iterator::operator-=(difference_type offset) {
        // while(offset--) {
        //     --ptr_to_data;
        // }
        ptr_to_data -= offset;
        return *this;
    }

    bool vector_iterator::operator==(const iterator_impl_base &rhs) const {
        return this->ptr_to_data == (dynamic_cast<const vector_iterator&>(rhs)).ptr_to_data;
    }
    bool vector_iterator::operator!=(const iterator_impl_base &rhs) const {
        return this->ptr_to_data != (dynamic_cast<const vector_iterator&>(rhs)).ptr_to_data;
    }
    bool vector_iterator::operator<(const iterator_impl_base &rhs) const {
        return this->ptr_to_data < (dynamic_cast<const vector_iterator&>(rhs)).ptr_to_data;
    }
    bool vector_iterator::operator>(const iterator_impl_base &rhs) const {
        return this->ptr_to_data > (dynamic_cast<const vector_iterator&>(rhs)).ptr_to_data;
    }
    bool vector_iterator::operator<=(const iterator_impl_base &rhs) const {
        return this->ptr_to_data <= (dynamic_cast<const vector_iterator&>(rhs)).ptr_to_data;
    }
    bool vector_iterator::operator>=(const iterator_impl_base &rhs) const {
        return this->ptr_to_data >= (dynamic_cast<const vector_iterator&>(rhs)).ptr_to_data;
    }

    difference_type vector_iterator::operator-(const iterator_impl_base &rhs) const {
        // revise here
        // solve the problem with (end - begin) != size
        return this->ptr_to_data - dynamic_cast<const vector_iterator&>(rhs).ptr_to_data;
    }
    pointer vector_iterator::operator->() const {
        return ptr_to_data;
    }
    reference vector_iterator::operator*() const {
        return *ptr_to_data;
    }
    reference vector_iterator::operator[](difference_type offset) const {
        // pointer temp = ptr_to_data;
        // temp += offset;
        // return *temp;
        return *(ptr_to_data+offset);
    }

    // my functions
    vector_iterator::vector_iterator(pointer p) : ptr_to_data(p) {}
    iterator_impl_base *vector_iterator::clone() const {
        return new vector_iterator(ptr_to_data); //will be deleted after destructor
    }
    Node* vector_iterator::node_ref() const {
        return nullptr;
    }
    
    //////////////////////////////////////
    //                                  //
    //			list_iterator           //
    //                                  //
    //////////////////////////////////////
    list_iterator::list_iterator() : _node(nullptr), _head(nullptr) {}
    iterator_impl_base &list_iterator::operator++() {
        _node = _node->next;
        return *this;
    }
    iterator_impl_base &list_iterator::operator--() {
        _node = _node->prev;
        return *this;
    }
    iterator_impl_base &list_iterator::operator+=(difference_type offset) {
        while(offset--) {
            _node = _node->next;
        }
        return *this;
    }
    iterator_impl_base &list_iterator::operator-=(difference_type offset) {
        while(offset--) {
            _node = _node->prev;
        }
        return *this;
    }

    bool list_iterator::operator==(const iterator_impl_base &rhs) const {
        return this->_node == (dynamic_cast<const list_iterator&>(rhs))._node;
    }
    bool list_iterator::operator!=(const iterator_impl_base &rhs) const {
        return this->_node != (dynamic_cast<const list_iterator&>(rhs))._node;
    }

    bool list_iterator::operator<(const iterator_impl_base &rhs) const {
        // list_iterator should not overload this operator
        // return this->_node < (dynamic_cast<const list_iterator&>(rhs))._node;

        difference_type head_to_this = 1, head_to_rhs = 1;
        Node* temp = _head->next;
        while(temp != _node) {
            temp = temp->next;
            head_to_this++;
        }
        temp = _head->next;
        while(temp != dynamic_cast<const list_iterator&>(rhs)._node) {
            temp = temp->next;
            head_to_rhs++;
        }
        return head_to_this < head_to_rhs;
    }
    bool list_iterator::operator>(const iterator_impl_base &rhs) const {
        // list_iterator should not overload this operator
        // return this->_node > (dynamic_cast<const list_iterator&>(rhs))._node;

        difference_type head_to_this = 1, head_to_rhs = 1;
        Node* temp = _head->next;
        while(temp != _node) {
            temp = temp->next;
            head_to_this++;
        }
        temp = _head->next;
        while(temp != dynamic_cast<const list_iterator&>(rhs)._node) {
            temp = temp->next;
            head_to_rhs++;
        }

        return head_to_this > head_to_rhs;
    }
    bool list_iterator::operator<=(const iterator_impl_base &rhs) const {
        // list_iterator should not overload this operator
        // return this->_node <= (dynamic_cast<const list_iterator&>(rhs))._node;

        difference_type head_to_this = 1, head_to_rhs = 1;
        Node* temp = _head->next;
        while(temp != _node) {
            temp = temp->next;
            head_to_this++;
        }
        temp = _head->next;
        while(temp != dynamic_cast<const list_iterator&>(rhs)._node) {
            temp = temp->next;
            head_to_rhs++;
        }

        return head_to_this <= head_to_rhs;
    }
    bool list_iterator::operator>=(const iterator_impl_base &rhs) const {
        // list_iterator should not overload this operator
        // return this->_node >= (dynamic_cast<const list_iterator&>(rhs))._node;

        difference_type head_to_this = 1, head_to_rhs = 1;
        Node* temp = _head->next;
        while(temp != _node) {
            temp = temp->next;
            head_to_this++;
        }
        temp = _head->next;
        while(temp != dynamic_cast<const list_iterator&>(rhs)._node) {
            temp = temp->next;
            head_to_rhs++;
        }

        return head_to_this >= head_to_rhs;
    }

    difference_type list_iterator::operator-(const iterator_impl_base &rhs) const {
        // maybe use recursive 
        // check 11423

        difference_type head_to_this = 1, head_to_rhs = 1;
        Node* temp = _head->next;
        while(temp != _node) {
            temp = temp->next;
            head_to_this++;
        }
        temp = _head->next;
        while(temp != dynamic_cast<const list_iterator&>(rhs)._node) {
            temp = temp->next;
            head_to_rhs++;
        }
        return head_to_this - head_to_rhs;
    }


    pointer list_iterator::operator->() const {
        return &(_node->data);
    }
    reference list_iterator::operator*() const {
        return _node->data;
    }
    reference list_iterator::operator[](difference_type offset) const {
        Node* temp = _node;
         //offset maybe < 0
        if(offset > 0) {
            while(offset--) {
                temp = temp->next;
            }
        } else if (offset < 0) {
            while(offset++) {
                temp = temp->prev;
            }
        }

        return temp->data;
    }

    // my functions
    list_iterator::list_iterator(Node* n, Node* h) : _node(n), _head(h) {}
    iterator_impl_base *list_iterator::clone() const {
        return new list_iterator(_node, _head);
    }
    Node* list_iterator::node_ref() const {
        return _node;
    }

} // namespace I2P2
