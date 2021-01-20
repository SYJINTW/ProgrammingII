#include "11419.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace oj;

void Vector::push_back(const_reference val) {
    size_t old_size = size();
    size_t old_capacity = capacity();

    if (old_capacity == old_size) {
        reserve(max(old_capacity + 1, old_capacity * 3));
    }
    
    new (last_++) value_type(val);
}

void Vector::erase(size_type pos) {
    begin_[pos].~value_type();

    for(pointer iter(begin_ + pos + 1); iter != last_; iter++) {
        new (iter - 1) value_type(*iter);
        iter->~value_type();
    }

    last_--;
}

void Vector::reserve(size_type new_capacity) {
    size_t old_size = size();
    size_t old_capacity = capacity();

    if(new_capacity > old_capacity) {
        pointer temp(static_cast<pointer> (operator new[] (sizeof(value_type) * new_capacity)));
        for(size_t i = 0; i < old_size; ++i) {
            new (temp + i) value_type(begin_[i]);
            // begin_[i].~value_type();
        }
        if(begin_ != nullptr) //may be not needed this if
            this->~Vector();
            // operator delete[] (begin_);
        
        begin_ = temp;
        last_ = begin_ + old_size;
        end_ = begin_ + new_capacity;
    }
}

Vector::~Vector() {
    for(pointer iter = begin_; iter != last_; ++iter) {
        iter->~value_type();
    }
    operator delete[] (begin_);
}

namespace oj {

    Employee::Employee(const std::string &name) : name_(name), id_(ID_++) {}

    struct God {
        static Employee create(const std::string &name) {
            return Employee(name);
        }

        static bool find(const Employee &employee, const string name) {
            return employee.name_ == name;
        }

        static bool find(const Employee &employee, const unsigned int id) {
            return employee.id_ == id;
        }

        static void print(const Employee &employee) {
            cout << employee.id_ << " " << employee.name_ << endl;
        }
    };
    

    void add_employee(Vector &vec,const std::string &name) {
        vec.push_back(God::create(name));
    }

    void print(const Vector &vec) {
        for(int i=0; i<vec.size(); ++i) {
            God::print(vec[i]);
        }
    }

    void quit(Vector &vec,unsigned id) {
        for(int i=0; i<vec.size(); ++i) {
            if(God::find(vec[i], id)) {
                vec.erase(i);
                i--; //after earsing, stay the same i
            }
        }
    }

    void quit(Vector &vec,const std::string &name) {
        for(int i=0; i<vec.size(); ++i) {
            if(God::find(vec[i], name)) {
                vec.erase(i);
                i--; //after earsing, stay the same i
            }
        }
    }
}









