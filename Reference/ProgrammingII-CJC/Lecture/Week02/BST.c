// implement a binary search tree
// and its function for sorting
#include <stdio.h>
#include <stdlib.h>



// data structure for a tree node
typedef struct _Node{
    int data;
    struct _Node *left, *right;
} Node;

// to make a tree node with given data
Node *makeNode(int data){
    Node *root = (Node*)malloc(sizeof(Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

// build a binary search tree from an array a[n]
Node* buildBST(int *a, int n){
    int i;

    // take care of the special case
    if (n==0) return NULL;
    Node* root = makeNode(a[0]);

    // iter is an iterator, which help to traverse the tree
    Node *iter = root;
    i = 1;
    while(i<n) {
        if (a[i]> iter->data){ // insert to the right subtree
            // if the right is NULL, insert the node to the right
            if (iter->right == NULL){
                iter->right = makeNode(a[i]);
                i++;
                iter = root; // reset the iterator for the next node
            } else {
                // the right is not NULL, go to the right node
                iter = iter ->right;
            }
        } else {                // insert to the left subtree
            // if the left is NULL, insert the node to the left
            if (iter->left == NULL){
                iter->left = makeNode(a[i]);
                i++;
                iter = root; // reset the iterator for the next node
            } else {
                // the left is not NULL, go to the left node
                iter = iter ->left;
            }
        }
    }
    return root;
}

// print the sorted result from the BST
void print_sort(Node *root){
    if (root == NULL)
        return;
    // in-order traversal
    print_sort(root->left);
    printf("%d ", root->data);
    print_sort(root->right);
}

// insert one node to BST
void insertBST(Node** root_ptr, int data){
    // dereference first
    Node* root = *root_ptr;

    if (root == NULL)
        root = makeNode(data);
    else {
        // search the correct direction to insert the data
        if (root->data < data)
            insertBST(&(root->right), data);
        else
            insertBST(&(root->left), data);
    }
}


// test driver of BST
int main(){
    int data[10] = {4, 6, 3, 2, 8 , 7, 5, 0, 9, 1};
    int n = 10;

    Node* root = buildBST(data, n);
    print_sort(root);
    printf("\n");

    // alternative implementation
    Node *root1 = NULL;
    int i;
    for (i=0; i<n; i++)
        insertBST(&root1, data[i]);
    print_sort(root1);

    return 0;
}
