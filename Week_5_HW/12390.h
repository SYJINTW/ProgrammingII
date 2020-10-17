#include <stdio.h>
#include <stdlib.h>

#define right ptr_to_right_node
#define left ptr_to_left_node
#define num number

typedef struct _NODE
{
	int number;
	struct _NODE *ptr_to_right_node;
	struct _NODE *ptr_to_left_node;
} Node;

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end){
	int inorder_idx;

	if(inorder_start > inorder_end) return NULL;
	else;

	Node* root = (Node*)malloc(sizeof(Node));
	root->num = *preorder;
	root->left = NULL;
	root->right = NULL;

	if(inorder_start != inorder_end){
		for(inorder_idx = inorder_start; inorder_idx < inorder_end; inorder_idx++){
			if(inorder[inorder_idx] == *preorder) break;
		}
		root->left = buildTree(inorder, preorder+1, inorder_start, inorder_idx-1);
		root->right = buildTree(inorder, preorder+(inorder_idx-inorder_start+1), inorder_idx+1, inorder_end);
	} else;
	return root;
}

void showPostorder(Node* root){
	if(root != NULL){
		showPostorder(root->left);
		showPostorder(root->right);
		printf("%d ", root->num);
	} else;
}

void freeTree(Node *root){
	if(root != NULL){
		freeTree(root->right);
		freeTree(root->left);
		free(root);
	} else;
}

