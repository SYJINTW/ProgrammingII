#include "../header/I2P2_Vector.h"
// #include <iostream>
// #include <algorithm>

// for those for loop, maybe use memmove?

namespace I2P2
{
    /* Your definition for the Vector class goes here */
    Vector::~Vector() {
        clear();
    }
    Vector::Vector() {
        buffer = nullptr;
        size_ = 0;
        capacity_ = 0;
    }
    Vector::Vector(const Vector &rhs) : Vector() {
        reserve(rhs.size());
        for(size_type i=0; i<rhs.size(); ++i) {
            buffer[i] = rhs.buffer[i];
        }
        size_ = rhs.size();
    }
    Vector& Vector::operator=(const Vector &rhs) {
        if(this != &rhs) {
            if(buffer != nullptr) {
                this->~Vector();
            }
            new (this) Vector(rhs);
        }
        return *this;
    }
    iterator Vector::begin() {
        vector_iterator vi(buffer);
        return iterator(&vi);
    }
    const_iterator Vector::begin() const {
        vector_iterator vi(buffer);
        return const_iterator(&vi);
    }
    iterator Vector::end() {
        vector_iterator vi = vector_iterator(buffer+size_);
        return iterator(&vi);
    }
    const_iterator Vector::end() const {
        vector_iterator vi = vector_iterator(buffer+size_);
        return const_iterator(&vi);
    }
    reference Vector::front() {
        return buffer[0];
    }
    const_reference Vector::front() const {
        return buffer[0];
    }
    reference Vector::back() {
        return buffer[size_-1];
    }
    const_reference Vector::back() const {
        return buffer[size_-1];
    }

    reference Vector::operator[](size_type pos) {
        return buffer[pos];
    }
    const_reference Vector::operator[](size_type pos) const {
        return buffer[pos];
    }
    size_type Vector::capacity() const {
        return capacity_;
    }
    size_type Vector::size() const {
        return size_;
    }


    void Vector::clear() { // reallocation is not garanteed
        delete [] buffer;
        buffer = nullptr;
        size_ = 0;
        capacity_ = 0;
    }
    bool Vector::empty() const {
        return size_ == 0;
    }

    // -----these four functions-----
    void Vector::erase(const_iterator pos) {
        size_type posNum = pos.operator->() - buffer;

        for(size_type i = posNum; i<size_-1; ++i) {
            buffer[i] = buffer[i+1];
        }
        size_--;
    }
    void Vector::erase(const_iterator begin, const_iterator end) {
        size_type beginNum = begin.operator->() - buffer;
        size_type length = end - begin;

        size_type i, sz = size();
        for(i = beginNum; i<sz-length; ++i) {
            buffer[i] = buffer[i+length];
        }
        size_ -= length;
    }
    void Vector::insert(const_iterator pos, size_type count, const_reference val) {
        size_type posNum = pos.operator->() - buffer;
        
        if(posNum > size_) return;

        size_type old_capacity_ = capacity_;
        if(old_capacity_ < size_ + count ) {
            old_capacity_ = (old_capacity_+count+posNum > 3*old_capacity_) ? (old_capacity_+count+posNum) : (3*old_capacity_);
            reserve(old_capacity_);
        }
        // when size == 0!!!!;
        if(!empty()) {
            for(size_type i=size_-1; i>=posNum; --i) {
                // 白癡喔size_type不會是負的喔= =
                buffer[i+count] = buffer[i];
                // new (buffer+i+count) value_type(buffer[i]);
                if(i == 0)
                    break;
            }
        }
        for(size_type i=posNum; i<posNum+count; ++i) {
            buffer[i] = val;
            // new (buffer+i) value_type(val);
        }
        size_ += count;
    }
    void Vector::insert(const_iterator pos, const_iterator begin, const_iterator end) {
        size_type posNum = pos.operator->() - buffer;
        // size_type length = end.operator->() - begin.operator->();
        size_type length = end - begin;

        if(posNum > size_) return;

        size_type old_capacity_ = capacity_;
        if(old_capacity_ < size_ + length ) {
            old_capacity_ = (old_capacity_+length+posNum > 3*old_capacity_) ? (old_capacity_+length+posNum) : (3*old_capacity_); //old_capacity_+length+posNum
            reserve(old_capacity_);
        }
        if(!empty()) {
            for(size_type i=size_-1; i>=posNum; --i) {
                // 白癡喔size_type不會是負的喔= =
                buffer[i+length] = buffer[i];
                // new (buffer+i+length) value_type(buffer[i]);
                if(i == 0)
                    break;
            }
        }
        for(size_type i=posNum; i<posNum+length; ++i) {
            buffer[i] = *(begin+i-posNum);
        }
        size_ += length;
    }
    // -----these four functions-----

    void Vector::pop_back() {
        size_--;
    }
    void Vector::pop_front() {
        for(size_type i = 0; i<size_-1; ++i) {
            buffer[i] = buffer[i+1];
        }
        size_--;
    }
    void Vector::push_back(const_reference val) {
        size_type old_capacity_ = capacity_;
        if(old_capacity_ < size_ + 1 ) {
            old_capacity_ = (old_capacity_+1 > 3*old_capacity_) ? (old_capacity_+1) : (3*old_capacity_);
            reserve(old_capacity_);
        }

        buffer[size_] = val;
        size_++;

    }
    void Vector::push_front(const_reference val) {
        size_type old_capacity_ = capacity_;
        if(old_capacity_ < size_ + 1 ) {
            old_capacity_ = (old_capacity_+1 > 3*old_capacity_) ? (old_capacity_+1) : (3*old_capacity_);
            reserve(old_capacity_);
        }
        for(size_type i = size_; i>0; --i) {
            buffer[i] = buffer[i-1];
        }
        buffer[0] = val;
        size_++;
    }
    void Vector::reserve(size_type new_capacity) {
        pointer new_buffer;

        if(capacity_ < new_capacity) {
            new_buffer = new value_type[new_capacity];
            for(size_type i = 0; i<size_; ++i) {
                new_buffer[i] = buffer[i];
            }
            if(buffer != nullptr) delete [] buffer;
            buffer = new_buffer;
            capacity_ = new_capacity;
        }
    }
    void Vector::shrink_to_fit() {
        pointer new_buffer;
        size_type new_capacity = size_;

        if(capacity_ > size_) {
            new_buffer = new value_type[new_capacity];
            for(size_type i = 0; i<size_; ++i) {
                new_buffer[i] = buffer[i];
            }
            if(buffer != nullptr) delete [] buffer;
            buffer = new_buffer;
            capacity_ = new_capacity;
        }
    }

} // namespace I2P2
