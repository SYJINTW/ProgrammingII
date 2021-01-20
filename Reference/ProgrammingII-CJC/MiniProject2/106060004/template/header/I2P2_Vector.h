#ifndef I2P2_VECTOR_H
#define I2P2_VECTOR_H

namespace I2P2
{
    template <class T>
    struct base_Vectoriterator
    {
        T* m_p_value;

        base_Vectoriterator(T* p) : m_p_value(p) {}

        base_Vectoriterator& operator++() {
            ++m_p_value;
            return *this;
        }
        base_Vectoriterator& operator--() {
            --m_p_value;
            return *this;
        }

        T& operator*() {
            return *m_p_value;
        }
        T* operator->() {
            return m_p_value;
        }
        bool operator==(const base_Vectoriterator &rhs) const {
            return m_p_value == rhs.m_p_value;
        }
    };

    template <class T>
    class Vector
    {
    private:
        T* buffer;
        size_t size_;
        size_t capacity_;
    public:
        typedef base_Vectoriterator<T> iterator;

        ~Vector();
        Vector();
        Vector(const Vector<T> &rhs);
        Vector<T> &operator=(const Vector<T> &rhs);
        iterator begin();
        iterator end();
        T& front();
        T& back();
        T& operator[](size_t pos);
        size_t capacity() const;
        size_t size() const;

        void clear();
        bool empty() const;
        void erase(iterator pos);
        void insert(iterator pos, T& val);
        void pop_back();
        void push_back(T& val);
        void reserve(size_t new_capacity);
        void shrink_to_fit();
    };

    // implementation
    template<class T>
    Vector<T>::~Vector() {
        clear();
    }

    template<class T>
    Vector<T>::Vector() {
        buffer = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    template<class T>
    Vector<T>::Vector(const Vector<T> &rhs) : Vector() {
        reserve(rhs.size());
        for(size_t i=0; i<rhs.size(); ++i) {
            // buffer[i] = rhs.buffer[i];
            new (buffer + i) T(rhs.buffer[i]);
        }
        size_ = rhs.size();
    }
    
    template<class T>
    Vector<T>& Vector<T>::operator=(const Vector<T> &rhs) {
        if(this != &rhs) {
            if(buffer != nullptr) {
                this->~Vector();
            }
            new (this) Vector(rhs);
        }
        return *this;
    }

    template<class T>
    typename Vector<T>::iterator Vector<T>::begin() {
        iterator it(buffer);
        return it;
    }

    template<class T>
    typename Vector<T>::iterator Vector<T>::end() {
        iterator it(buffer+size_);
        return it;
    }

    template<class T>
    T& Vector<T>::front() {
        return buffer[0];
    }

    template<class T>
    T& Vector<T>::back() {
        return buffer[size_ - 1];
    }

    template<class T>
    T& Vector<T>::operator[](size_t pos) {
        return buffer[pos];
    }

    template<class T>
    size_t Vector<T>::capacity() const {
        return capacity_;
    }

    template<class T>
    size_t Vector<T>::size() const {
        return size_;
    }

    template<class T>
    void Vector<T>::clear() {
        delete [] buffer;
        buffer = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    template<class T>
    bool Vector<T>::empty() const {
        return size_ == 0;
    }

    template<class T>
    void Vector<T>::erase(iterator pos) {
        size_t posNum = pos.operator->() - buffer;
        for(size_t i = posNum; i<size_-1; ++i) {
            // buffer[i] = buffer[i+1];
            new (buffer+i) T(buffer[i+1]);
        }
        size_--;
    }

    template<class T>
    void Vector<T>::insert(iterator pos, T& val) {
        size_t posNum = pos.operator->() - buffer;
        size_t old_capacity = capacity_;
        if(old_capacity < size_ + 1) {
            old_capacity = (old_capacity+1 > 2*old_capacity) ? old_capacity+1 : 2*old_capacity;
            reserve(old_capacity);
        }
        if(!empty()) {
            for(size_t i=size_-1; i>=posNum; --i) {
                buffer[i+1] = buffer[i];
                if(i == 0)
                    break;
            }
        }
        buffer[posNum] = val;
        size_++;
    }

    template<class T>
    void Vector<T>::pop_back() {
        size_--;
    }

    template<class T>
    void  Vector<T>::push_back(T& val) {
        size_t old_capacity_ = capacity_;
        if(old_capacity_ < size_ + 1 ) {
            old_capacity_ = (old_capacity_+1 > 2*old_capacity_) ? (old_capacity_+1) : (2*old_capacity_);
            reserve(old_capacity_);
        }
        new (buffer + size_) T(val);
        size_++;
    }

    template<class T>
    void Vector<T>::reserve(size_t new_capacity) {
        T* new_buffer;

        if(capacity_ < new_capacity) {
            new_buffer = new T[new_capacity];
            for(size_t i=0; i<size_; ++i) {
                // new_buffer[i] = buffer[i];
                new (new_buffer+i) T(buffer[i]);
            }
            delete [] buffer;
            buffer = new_buffer;
            capacity_ = new_capacity;
        }
    }

    template<class T>
    void Vector<T>::shrink_to_fit() {
        T* new_buffer;
        size_t new_capacity = size_;

        if(capacity_ > new_capacity) {
            new_buffer = new T[new_capacity];
            for(size_t i=0; i<size_; ++i) {
                // new_buffer[i] = buffer[i];
                new (new_buffer+i) T(buffer[i]);
            }
            delete [] buffer;
            buffer = new_buffer;
            capacity_ = new_capacity;
        }
    }
}

#endif