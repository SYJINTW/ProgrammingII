#include<iostream>
#include"function.h"
using namespace std;
using namespace oj;

void Vector::pop_back(){
	if(size()>0) last_--;
}

void Vector::push_back(value_type val){
	if(size()>=capacity()){
		size_type new_capacity = (capacity()+1>capacity()*3)?(capacity()+1):(capacity()*3);
		reserve(new_capacity);
	}
	*last_ = val;
	last_++;
}

void Vector::reserve(size_type new_capacity){
	if(new_capacity > capacity()){
		pointer new_begin = new value_type[new_capacity];
		for(int i=0;i<size();i++){
			new_begin[i] = begin_[i];
		}
		size_type old_size = size();
		delete[] begin_;
		begin_ = new_begin;
		last_ = new_begin + old_size;
		end_ = new_begin + new_capacity;
	}
}

Vector::~Vector(){
	delete []begin_;
}
