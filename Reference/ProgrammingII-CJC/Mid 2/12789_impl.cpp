#include "12789.h"
#include <iostream>

using namespace std;
using namespace oj;

void weakpal::setStr(const std::string & _str) {
    this->str = _str;
}
void weakpal::setDis() {
    int i = 0, j = str.size()-1;

    int tempDis = 0;
    while(i <= j) {
        if(str[i] != str[j]) {
            tempDis++;
        }
        i++;
        j--;
    }
    this->dis = tempDis;
}

bool weakpal::operator<( const weakpal & rhs ) {
    cout << "Test\n";
    if(this->dis < rhs.dis) {
        return true;
    } else if (this->dis > rhs.dis) {
        return false;
    } else {
        int i=0;
        while(i<this->str.size() && i <rhs.str.size()) {
            if(this->str[i] < rhs.str[i]) {
                return true;
            } else if (this->str[i] > rhs.str[i]) {
                return false;
            } else {
                i++;
            }
        }
        // return true;
    }
}

void BST::insertNode(std::string& s) {
    Node* newNode = new Node();

    weakpal* newWeakpal = new weakpal();
    newWeakpal->setStr(s);
    newWeakpal->setDis();

    newNode->data = newWeakpal;

    if(root == nullptr) {
        root = newNode;
    } else {
        bool done = false;
        Node* temp = root;
        while(!done) {
            if(*(temp->data) < *(newNode->data)) {
                if(temp->right == nullptr) {
                    temp->right = newNode;
                    done = true;
                } else {    
                    temp = temp->right;
                }
            } else if (*(newNode->data) < *(temp->data)){
                if(temp->left == nullptr) {
                    temp->left = newNode;
                    done = true;
                } else {    
                    temp = temp->left;
                }
            }
        }
    }
}