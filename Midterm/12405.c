#include <stdio.h>
#include <stdlib.h>

typedef struct t_Node{
	int number;
	struct t_Node* left;
	struct t_Node* right;
} Node;

int inorder_list[105];
int postorder_list[105];

Node* createTree(int* inorder, int* postorder, int l, int r){
	//if doesn't exist
	if(l > r) return NULL;
	else;

	int index;
	Node* root = (Node*)malloc(sizeof(Node));
	root->number = *postorder;
	//printf("%d", *postorder);
	root->right = NULL;
	root->left = NULL;
	if(l < r){
		for(index = r; index > l; index--){
			if(inorder[index] == *postorder) break;
			else;
		}
		root->right = createTree(inorder, postorder-1, index+1, r);
		root->left = createTree(inorder, postorder-(r-index+1), l, index-1);
	}
	return root;

}

//for check
void inorder(Node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->number);
		inorder(root->right);
	} else;
}

//for check
void postorder(Node* root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->number);
	} else;
}

void preorder(Node* root){
	if(root != NULL){
		printf("%d ", root->number);
		preorder(root->left);
		preorder(root->right);
	} else;
}

void freeTree(Node* root){
	if(root != NULL){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	} else;

}

int main(){
	int id = 1;
	int n;
	Node* root = NULL;


	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", inorder_list+i);
		}
		for(int i = 0; i < n; i++){
			scanf("%d", postorder_list+i);
		}

		root = createTree(inorder_list, postorder_list+(n-1), 0, n-1);

		/*
		//check
		inorder(root);
		printf("\n");
		postorder(root);
		printf("\n");
		*/

		printf("testcase%d: ", id++);
		preorder(root);
		printf("\n");

		freeTree(root);
		root = NULL;
	}
	return 0;
}
