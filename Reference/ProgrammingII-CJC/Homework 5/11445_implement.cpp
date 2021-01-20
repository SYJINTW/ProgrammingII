#include "11445.h"
#include <iostream>

using namespace oj;
using namespace std;

Vector::Vector(){
    begin_ = nullptr;
    end_ = nullptr;
    last_ = nullptr;
}

// since c++ 11, you can do that :Vector()
Vector::Vector(const Vector &rhs):Vector(){
    //allocate new space and make copy
    reserve(rhs.size());

    int sz = rhs.size();
    for(int i=0; i<sz; ++i){
        begin_[i] = rhs.begin_[i];
    }
    last_ = begin_ + sz;
}

Vector& Vector::operator=(const Vector &rhs){
    if(this != &rhs){
        if(begin_ != nullptr){
            this->~Vector(); 
        }
        // only delete begin_
        // "this" object is still available
        new (this) Vector(rhs);
    }
    return *this;
}

void Vector::erase(size_type pos){
    size_type i, sz = size();

    if(pos < 0 || pos >= sz)
        return;

    for(i = pos; i<sz-1; ++i) {
        begin_[i].~value_type();
        new (begin_+i) value_type(begin_[i+1]);
        // begin_[i] = begin_[i+1];
    }
    last_--;
}

void Vector::insert(size_type pos, const_reference val){
    size_type cap = capacity();
    size_type i, sz = size();

    if(cap < sz+1) {
        cap = (cap+1 > 3*cap) ? cap+1 : 3*cap;
        reserve(cap);
    }

    if(pos < sz) {
        for(i=sz; i>pos; --i){
            begin_[i].~value_type();
            new (begin_+i) value_type(begin_[i-1]);
            // begin_[i] = begin_[i-1];
        }
    }
    // cout << "typeof begin_[0]: "<< typeid(begin_[0]).name() << endl;

    begin_[pos].~value_type();
    new (begin_+pos) value_type(val);
    // begin_[pos] = value_type(val);
    last_++;
}

void Vector::reserve(size_type new_capacity) {
    pointer new_storage;
    size_type i, sz;

    if(capacity() < new_capacity) {
        // allocate new storage
        new_storage = (pointer)operator new[](sizeof(value_type) * new_capacity);
        sz = size();

        // cout << "typeof new_storage[0]: "<< typeid(new_storage[0]).name() << endl;

        // init with copying data
        // you can also use "uninitialized copy" instead
        for(i=0; i<sz; ++i){
            new (new_storage+i) value_type(begin_[i]);
            // new_storage[i] = value_type(begin_[i]);
        }

        for(i=sz; i<new_capacity; ++i){
            new (new_storage+i) value_type("");
            // new_storage[i] = value_type("");
        }

        if(begin_ != nullptr){
            this->~Vector();
        }

        begin_ = new_storage;
        last_ = begin_ + sz;
        end_ = begin_ + new_capacity;
    }
}

Vector::~Vector() {
    for(pointer iter = begin_; iter != last_; ++iter){
        iter->~value_type();
    }
    operator delete[](begin_);
    // operator delete + destruct
    // equal to delete
}