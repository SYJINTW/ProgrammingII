#include <stdio.h>
#include <stdlib.h>
#include "11349.h"
void destroyTree(Node *root)
{
    if(root != NULL)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}
int main(void)
{
    int n;
    Node *root = NULL;
    scanf("%d",&n);
    create_tree(&root, n);
    print_tree(root);
    destroyTree(root);
    return 0;
}

void insertNode(Node* curNode, Node* goalNode){
    if(goalNode->data > curNode->data){
        if(curNode->right == NULL){
            curNode->right = goalNode;
        }else{
            insertNode(curNode->right, goalNode);
        }
    }else if(goalNode->data < curNode->data){
        if(curNode->left == NULL){
            curNode->left = goalNode;
        }else{
            insertNode(curNode->left, goalNode);
        }
    }
}

void create_tree(Node **root, int n){
    for(int i=0 ; i<n ; ++i){
        int num;
        scanf("%d", &num);

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = num;
        newNode->right = NULL;
        newNode->left = NULL;

        if(!(*root)){
            *root = newNode;
        }else{
            insertNode(*root, newNode);
        }
    }
}

void print_preorder(Node *curNode){\
    if(!curNode)
        return;
    printf(" %d", curNode->data);
    print_preorder(curNode->left);
    print_preorder(curNode->right);
}
void print_inorder(Node *curNode){
    if(!curNode)
        return;
    print_inorder(curNode->left);
    printf(" %d", curNode->data);
    print_inorder(curNode->right);
}
void print_postorder(Node *curNode){
    if(!curNode)
        return;
    print_postorder(curNode->left);
    print_postorder(curNode->right);
    printf(" %d", curNode->data);
}
void print_tree(Node *root){
    printf("preorder:");
    print_preorder(root);
    printf("\n");

    printf("inorder:");
    print_inorder(root);
    printf("\n");

    printf("postorder:");
    print_postorder(root);
    printf("\n");
}