
// #define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

#include "12715.h"
#include <iostream>
#include <cstring>

using namespace std;
using namespace oj;

BigInt::BigInt(char *s) {
    this->_val = new char[1024];
    strcpy(this->_val, s);
}

BigInt::~BigInt() {
    delete (this->_val);
}

BigInt& BigInt::operator++() {
    //-----add one-----
    int carry = 1;
    for(int i=strlen(_val)-1; i>=0 && carry; --i){
        if(_val[i] + carry > '9'){
            _val[i] = '0';
            carry = 1;
        } else {
            _val[i]++;
            carry = 0;
        }
    }
    if (carry) { //考慮進位到沒空間的地方
        // char* new_val = new char[strlen(_val) + 2];
        // new_val[0] = '1';
        // strcpy(&new_val[1], _val);
        // delete _val;
        // _val = new_val;
        strcpy(_val+1, _val);
        _val[0] = '1';
    }
    //-----add one-----
    return *this;
}

BigInt BigInt::operator++(int num) {
    BigInt* temp = new BigInt(_val);
    //-----add one-----
    int carry = 1;
    for(int i=strlen(_val)-1; i>=0 && carry; --i){
        if(_val[i] + carry > '9'){
            _val[i] = '0';
            carry = 1;
        } else {
            _val[i]++;
            carry = 0;
        }
    }
    if (carry) { //考慮進位到沒空間的地方
        // char* new_val = new char[strlen(_val) + 2];
        // new_val[0] = '1';
        // strcpy(&new_val[1], _val);
        // delete _val;
        // _val = new_val;
        strcpy(_val+1, _val);
        _val[0] = '1';
    }
    //-----add one-----
    return *temp;
}

BigInt& BigInt::operator--() {
    //-----subtract one-----
    if(_val[0] == '0')
        return *this;
    int borrow = 1;
    for(int i=strlen(_val)-1; i>=0 && borrow; --i) {
        if(_val[i] - borrow < '0'){
            _val[i] = '9';
            borrow = 1;
        } else {
            _val[i]--;
            borrow = 0;
        }
    }
    if(strlen(_val) > 1 && _val[0] == '0'){
        // char* new_val = new char[strlen(_val)];
        // strcpy(new_val, _val + 1);
        // delete _val;
        // _val = new_val;
        strcpy(_val, _val+1);
    }
    //-----subtract one-----
    return *this;
}

BigInt BigInt::operator--(int num) {
    BigInt* temp = new BigInt(_val);
    //-----subtract one-----
    if(_val[0] == '0')
        return *temp;
    int borrow = 1;
    for(int i=strlen(_val)-1; i>=0 && borrow; --i) {
        if(_val[i] - borrow < '0'){
            _val[i] = '9';
            borrow = 1;
        } else {
            _val[i]--;
            borrow = 0;
        }
    }
    if(strlen(_val) > 1 && _val[0] == '0'){ //處理開頭的0
        // char* new_val = new char[strlen(_val)];
        // strcpy(new_val, _val + 1);
        // delete _val;
        // _val = new_val;
        strcpy(_val, _val+1);
    }
    //-----subtract one-----
    return *temp;
}

char* BigInt::to_s() {
    return this->_val;
}