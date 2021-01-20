#include "12721.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace oj;
using namespace std;

BST::BST() {
    root = nullptr;
}

void deleteBST(Node* root){
    if(root == nullptr)
        return;
    deleteBST(root->lc);
    deleteBST(root->rc);
    delete root;
}

BST::~BST() {
    deleteBST(root);
}

void BST::insert(int val) {
    Node* iter;
    bool done = false;

    if(root == nullptr){
        root = new Node(val);
    } else {
        iter = root;
        while(!done) {
            if(iter->val == val) {
                done = true;
            } else if (iter->val > val) {
                if(iter->lc == nullptr){
                    Node* newNode = new Node(val);
                    iter->lc = newNode;
                    done = true;
                } else {
                    iter = iter->lc;
                }
            } else {
                if(iter->rc == nullptr){
                    Node* newNode = new Node(val);
                    iter->rc = newNode;
                    done = true;
                } else {
                    iter = iter->rc;
                }
            }
        }
    }
}

Node* minValueNode(Node* root) {
    Node* curNode = root;
    while(curNode && curNode->lc != nullptr){
        curNode = curNode->lc;
    }
    return curNode;
}

Node* eraseNode(Node* root, int val){
    if(root == nullptr)
        return nullptr;
    Node* temp;

    if(root->val > val) {
        root->lc = eraseNode(root->lc, val);
        return root;
    } else if (root->val < val) {
        root->rc = eraseNode(root->rc, val);
        return root; 
    } else { // (root->val == val)
        if (root->lc == nullptr){
            temp = root->rc;
            delete root;
            return temp;
        } else if (root->rc == nullptr){
            temp = root->lc;
            delete root;
            return temp;
        } else {
            temp = minValueNode(root->rc);
            root->val = temp->val;

            root->rc = eraseNode(root->rc, temp->val);
        }

        return root;
    }
}

void BST::erase(int val) {
    root = eraseNode(root, val);
}

void in_order(stringstream &ss, Node* root){
    if(root == nullptr) 
        return;
    in_order(ss, root->lc);
    ss << root->val << " ";
    in_order(ss, root->rc);
}

string BST::inorder(){
    stringstream ss("");
    in_order(ss, root);
    string s = ss.str();
    if (s[s.length()-1]== ' '){
        return s.substr(0, s.length()-1);
    }
    return s;
}