#include "12722.h"
#include <iostream>

using namespace std;
using namespace oj;

void Fib::setBase(int x, int y) {
    this->a0 = x;
    this->a1 = y;
}

// int64_t Fib::operator[](int index) {
//     if(index == 0)
//         return this->a0;
//     else if(index == 1)
//         return this->a1;
//     else 
//         return Fib::operator[](index-1) + Fib::operator[](index-2);
// }

int64_t Fib::operator[](int index) {
    if(a0 == 0 && a1 == 0)
        return 0;
    if(index == 0)
        return a0;
    else if(index == 1)
        return a1;
    
    int64_t sum0 = a0, sum1 = a1;
    for(int i=2; i<=index; ++i){
        int64_t temp = sum1;
        sum1 += sum0;
        sum0 = temp;
    }
    return sum1;
}

