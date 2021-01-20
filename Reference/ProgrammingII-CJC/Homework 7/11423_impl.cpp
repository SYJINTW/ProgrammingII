#include <iostream>
#include "11423.h"

using namespace std;

namespace oj {

Node::Node() {
    val = 0;
    next = nullptr;
    prev = nullptr;
}

Iter::Iter(data_t *begin) {
    this->p_ = begin;
}

std::ptrdiff_t Random_iter::distance_(const Iter &begin,const Iter &end) const {
    int i=0;
    data_t *tempP = begin.get();
    data_t *goalP = end.get();
    while(tempP != goalP) {
        tempP++;
        i++;
    }
    return i;
}

void Random_iter::next_(Iter &des) const {
    // Iter *iter(new Random_iter(get()+1));
    Random_iter* tempIter = new Random_iter(get()+1);
    des.assign(*tempIter);
}
void Random_iter::prev_(Iter &des) const {
    Iter *iter(new Random_iter(get()-1));
    des.assign(*iter);
}

Random_iter::Random_iter(data_t *begin) :Iter(begin) {}

std::ptrdiff_t Bidirect_iter::distance_(const Iter &begin,const Iter &end) const {
    int i=0;
    data_t *tempP = begin.get();
    data_t *goalP = end.get();
    while(tempP != goalP) {
        tempP = tempP->next;
        i++;
    }
    return i;
}
void Bidirect_iter::next_(Iter &des) const {
    Iter *iter = new Bidirect_iter(get()->next);
    des.assign(*iter);
}
void Bidirect_iter::prev_(Iter &des) const {
    Iter *iter = new Bidirect_iter(get()->prev);
    des.assign(*iter);
}

Bidirect_iter::Bidirect_iter(data_t *begin) :Iter(begin) {}

}

