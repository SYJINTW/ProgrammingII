#include "function.h"
#include <iostream>
using namespace std;
Array_BST::Array_BST()
    :BST()
{
    for(int i=0;i<1025;i++){
        array[i] = 0;
    }
}

void Array_BST::insert(const int& data){
    int count=1;
    int idx =1;
    while(array[idx]!=0){
        if(data<array[idx])
            idx = idx*2;
        else if(data>array[idx])
            idx = idx*2+1;
        else if(data == array[idx])
            return;
        count++;
    }
    array[idx] = data;
    if(count>Height)
        Height = count;
}

bool Array_BST::search(const int& data) const{
    int idx=1;
    while(idx<1025){
        if(data==array[idx])
            return true;
        else if(data<array[idx])
            idx=idx*2;
        else if(data>array[idx])
            idx=idx*2+1;
    }
    return false;
}

List_BST::List_BST()
    :BST(),root(NULL){

}

void List_BST::insert(const int& data){
    int count=1;
    ListNode* new_node = createLeaf(data);
    if(Height==0){
        root = new_node;
    }
    else{
        ListNode* temp = root;
        while(temp!=NULL){
            if(data<temp->key){
                if(temp->left==NULL){
                    temp->left=new_node;
                    count++;
                    break;
                }
                temp=temp->left;
            }
            else if(data>temp->key){
                if(temp->right==NULL){
                    temp->right = new_node;
                    count++;
                    break;
                }
                temp = temp->right;
            }
            else if (data==temp->key)
                return;
            count++;
        }
    }
    if(count>Height)
        Height = count;
}

bool List_BST::search(const int& data)const{
    ListNode* temp = root;
    while(temp!=NULL){
        if(data==temp->key)
            return true;
        else if(data<temp->key){
            temp = temp->left;
        }
        else if(data>temp->key){
            temp = temp->right;
        }
    }
    return false;
}

ListNode* List_BST::createLeaf(int key)const{
    ListNode* new_node = new ListNode(key);
    return new_node;
}

void List_BST::deleteTree(ListNode* root){
    if(root==NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
