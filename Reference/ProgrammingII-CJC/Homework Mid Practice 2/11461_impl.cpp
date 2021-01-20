#include "11461.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace oj;

Vector::Vector() {
    begin_ = nullptr;
    end_ = nullptr;
    last_ = nullptr;
}

Vector::~Vector() {
    for(pointer iter = begin_; iter != last_; ++iter){
        iter->~value_type();
    }
    operator delete[](begin_);
}


Vector::Vector(const Vector &rhs) : Vector(){
    reserve(rhs.size());

    size_type sz = rhs.size();
    for(int i=0; i<sz; ++i){
        // begin_[i] = rhs.begin_[i];
        new (begin_ + i) value_type(rhs[i]);
    }
    last_ = begin_ + sz;
}

Vector& Vector::operator=(const Vector &rhs) {
    // if (this != &rhs){
    //     reserve(rhs.size());
    //     this->last_ = this->begin_ + rhs.size();

    //     for(pointer iter = begin_; iter != last_; ++iter){
    //         iter->~value_type();
    //     }

    //     for (size_type i = 0; i < rhs.size(); i++){
    //         new (this->begin_ + i) value_type(rhs[i]);
    //     }
    // }
    // return *this;
    if(this != &rhs){
		size_type cap = capacity();
		
        if(begin_ != nullptr){
            this->~Vector();
        }

        new (this) Vector(rhs);
		reserve(cap);
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
    }
    last_--;
}

void Vector::insert(size_type pos, const_reference val){
    size_type cap = capacity();
    size_type i, sz = size();

    if(pos < 0 || pos > sz)
        return;

    if(cap < sz+1) {
        cap = (cap+1 > 3*cap) ? cap+1 : 3*cap;
        reserve(cap);
    }

    if(pos < sz) {
        for(i=sz; i>pos; --i){
            begin_[i].~value_type();
            new (begin_+i) value_type(begin_[i-1]);
        }
    }

    begin_[pos].~value_type();
    new (begin_+pos) value_type(val);
    last_++;
}

void Vector::reserve(size_type new_capacity) {
    pointer new_storage;
    size_type i, sz;

    if(capacity() < new_capacity) {
        // allocate new storage
        new_storage = static_cast<pointer>(operator new[](sizeof(value_type) * new_capacity));
        sz = size();

        // init with copying data
        // you can also use "uninitialized copy" instead
        for(i=0; i<sz; ++i){
            new (new_storage+i) value_type(begin_[i]);
        }

        for(i=sz; i<new_capacity; ++i){
            new (new_storage+i) value_type("");
        }

        if(begin_ != nullptr){
            this->~Vector();
        }

        begin_ = new_storage;
        last_ = begin_ + sz;
        end_ = begin_ + new_capacity;
    }
}