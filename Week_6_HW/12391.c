#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int arr[10000000];
int n, q;
int x;

typedef struct t_Node{
	int index;
	int value;
	struct t_Node* left;
	struct t_Node* right;
} Node;

void builtTree(Node** root, int l, int r){
	if(l > r){
		(*root) = NULL;
		return;
	} else;
	//mid of arr
	int mid = (l+r)/2;
	//create node 
	(*root) = (Node*)malloc(sizeof(Node));
	(*root)->index = mid;
	(*root)->value = arr[mid];

	if(l == r){
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else{
		builtTree(&((*root)->left), l, mid-1);
		builtTree(&((*root)->right), mid+1, r);
	}
}

void search(Node* root){
	//can't find
	if(root == NULL){
		printf("Break your bridge!\n");
		return;
	}
	else;

	//x == root
	if(root->value == x){
		printf("%d\n", root->index);
	}
	//x < root, find left
	else if(root->value > x){
		search(root->left);
	}
	//x > root, find right
	else if(root->value < x){
		search(root->right);
	}
}

void freeTree(Node* root){
	if(root != NULL){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	} else;
}

/*
void inorder(Node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->value);
		inorder(root->right);
	} else;
}
*/

int main(){
	Node* root = NULL;
	while(scanf("%d %d", &n, &q) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d", &arr[i]);
		}
		//printf("Finish creating arr\n");
		builtTree(&root, 1, n);
		//printf("Finish creating tree\n");
		//inorder(root);
		while(q--){
			scanf("%d", &x);
			search(root);
		}
		freeTree(root);
		root = NULL;
	}
	return 0;
}