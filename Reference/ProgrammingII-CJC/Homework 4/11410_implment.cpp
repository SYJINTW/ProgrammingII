#include "11410.h"
#include <iostream>

using namespace oj;
using namespace std;

Vector::Vector() {
    begin_ = nullptr;
    end_ = nullptr;
    last_ = nullptr;
}

Vector::~Vector() {
    if(begin_ != nullptr){
        delete [] begin_;
    }
}

Vector::size_type Vector::capacity() const {
    return end_ - begin_;
}

Vector::size_type Vector::size() const {
    return last_ - begin_;
}

void Vector::pop_back() {
    if(size() > 0){
        last_--;
    }
}
void Vector::push_back(value_type val) {
    int cap = capacity();
    int sz = size();

    if (cap - sz < 1){
        cap = (cap+1 > cap*3) ? (cap+1) : (cap*3);
        reserve(cap);
    }
    // begin_[sz] = val;
    // last_++;

    *last_ = val;
    last_++;
}
void Vector::insert(size_type pos,size_type count,value_type val) {
    int cap = capacity();
    int sz = size();

    if(cap - sz < count) {
        cap = cap + ((cap/2>count) ? cap/2 : count);
        reserve(cap);
    }

    if(pos < sz){
        for(int i=pos; i<sz; ++i){
            begin_[i+count] = begin_[i];
        }
    }

    for(int i=pos; i<pos+count ; ++i){
        begin_[i] = val;
    }

    last_ += count;
}

void Vector::reserve(size_type new_capacity) {
    int cap = capacity();
    int sz = size();

    if (new_capacity > cap) {
        pointer newStorage = new Int[new_capacity];

        // copy data
        for(int i=0; i<sz; ++i) {
            newStorage[i] = begin_[i];
        }

        // delete the old storage
        if (begin_ != nullptr)
            delete [] begin_;

        begin_ = newStorage;
        last_ = begin_ + sz;
        end_ = begin_ + new_capacity;
    }
}
void Vector::resize(size_type new_size) {
    int cap = capacity();
    int sz = size();
    reserve(new_size);
    
    for(int i=sz; i<new_size; ++i){
        begin_[i] = 0;
    }

    last_ = begin_ + new_size;
}
