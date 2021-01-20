#include <bits/stdc++.h>
#include "function.h"

using namespace std;
using namespace oj;

BST::BST(){
    root = nullptr;
}

void deleteBST(Node* root){
    // your code here
}

BST::~BST(){
    deleteBST(root);
}

void BST::insert(int v){
    Node* iter;
    int done = 0;

    if (root==nullptr){ // set v as the root
        root = new Node(v);
    } else {
        // start to traverse the BST
        iter = root;
        while (!done){
            if (iter->val == v){
                // for repeated value, ignore it.
                done = 1;
            } else if (iter->val > v){
                // v is smaller than the current node
                // add it to the left subtree
                // your code here
            } else {
                // v is larger than the current node
                // add it the right subtree
                // your code here
            }
        }
    }
}

Node* eraseNode(Node* root, int v) {
    if (!root) return nullptr;
    Node* curr;

    if (root->val > v) {
        root->lc = eraseNode(root->lc, v);
        return root;
    } else if (root->val < v) {
        root->rc = eraseNode(root->rc, v);
        return root;
    } else { // root->val == v: remove root
        if (root->lc == nullptr){ // left child is null
            // your code here
        } else if(root->rc == nullptr){ // right child is null
            // your code here
        } else {// Neither left nor right is null.
            // your code here
        }
    }
}

void BST::erase(int v){
    root = eraseNode(root, v);
}


void in_order(stringstream &ss, Node* root){
    if(root!=nullptr){
        in_order(ss, root->lc);
        ss << root->val << " ";
        in_order(ss, root->rc);
    }
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
