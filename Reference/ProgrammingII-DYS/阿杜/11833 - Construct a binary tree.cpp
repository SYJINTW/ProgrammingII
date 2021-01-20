#include <stdlib.h>
#include <stdio.h>
typedef struct _node {
    int value;
    struct _node *left;
    struct _node *right;
} Node;

int in_Tra_index[200005];
Node *build(int *inorder, int *preorder, int inorder_start, int inorder_end);

Node *create_node(int value){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void postorder(Node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->value);
	}
	return;
}
void destroy(Node* root){
	if(root!=NULL){
		destroy(root->left);
		destroy(root->right);
		free(root);
	}
	return;
}

int main(){
	int N;
	scanf("%d",&N);
	int in_Tra[N];
	int pre_Tra[N];
	
	for(int i=0;i<N;i++){
		scanf("%d",&in_Tra[i]);
		in_Tra_index[in_Tra[i]] = i;
	}
	
	for(int i=0;i<N;i++){
		scanf("%d",&pre_Tra[i]);
	}
	Node *root;
	root = build(in_Tra,pre_Tra,0,N-1);
	postorder(root);
	printf("\n");
	destroy(root);
	return 0;
}
/*
    Parameter description:
    int *inorder : the inorder traversal sequence of the binary tree.
    int *preorder : the preorder traversal sequence of the binary tree.
    int inorder_start : the starting index of the inorder traversal of the subtree.
    int inroder_end : the ending index of the inorder traversal of the subtree.

    As for the preorder traversal index, try declaring a static variable inside this function.
*/
Node *build(int *inorder, int *preorder, int inorder_start, int inorder_end){
	static int index_pre = 0;
	if(inorder_start>inorder_end)
		return NULL;
	Node *root = create_node(*(preorder+index_pre));
	index_pre++;
	if(inorder_start==inorder_end)
		return root;
	int index_in = in_Tra_index[root->value];
	root->left = build(inorder,preorder,inorder_start,index_in-1);
	root->right = build(inorder,preorder,index_in+1,inorder_end);
	return root;
}
