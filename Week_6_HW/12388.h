#include<stdio.h>
#include <stdlib.h>
#define MAX_N 1000006
#define left left_child
#define right right_child


typedef struct _NODE {
	int level;
	struct _NODE *left_child, *right_child;
} Node;

void build_tree(Node **now, int *arr, int l, int r){
	if(l > r) return; // out of boundary
	else;

	int mid = (l+r)/2; // mid pos as the root
	(*now) = (Node*)malloc(sizeof(Node));
	(*now)->level = arr[mid];
	(*now)->left = NULL;
	(*now)->right = NULL;
	if(l != r){
		build_tree(&((*now)->left), arr, l, mid-1);
		build_tree(&((*now)->right), arr, mid+1, r);
	} else;
}

int query_heatstroke(Node *now, int x){
	if(now == NULL){
		return 0; // cannot found
	}
	else if(x == now->level){
		return 1; // found
	}
	else if(x < now->level){
		return query_heatstroke(now->left, x); // find left
	}
	else if(x > now->level){
		return query_heatstroke(now->right, x); // find right
	}
}

void eat_rat(Node **root, int x){
	Node* parent = NULL;
	Node* cur = (*root);
	// find cur->level that match x
	while(cur != NULL){
		if(x == cur->level) break;
		else if(x < cur->level){
			parent = cur;
			cur = cur->left;
		}
		else if(x > cur->level){
			parent = cur;
			cur = cur->right;
		} else;
	}

	//no match
	if(cur == NULL) return;
	else;

	//no child
	if(cur->left == NULL && cur->right == NULL){
		//cur is not main root
		if(cur != (*root)){
			if(parent->left == cur){
				parent->left = NULL;
			}
			else{
				parent->right = NULL;
			}
		}
		//cur is main root == the last element
		else{
			(*root) = NULL;
		}
		free(cur);
	}
	//left have child
	else if(cur->right == NULL){
		//cur is not main root
		if(cur != (*root)){
			if(parent->left == cur){
				parent->left = cur->left;
			}
			else{
				parent->right = cur->left;
			}
		}
		//cur is main root == the last element
		else{
			(*root) = cur->left;
		}
		free(cur);
	}
	//right have child
	else if(cur->left == NULL){
		//cur is not main root
		if(cur != (*root)){
			if(parent->left == cur){
				parent->left = cur->right;
			}
			else{
				parent->right = cur->right;
			}
		}
		//cur is main root == the last element
		else{
			(*root) = cur->right;
		}
		free(cur);
	}
	//two child
	else{
		Node* small = cur->left;
		int val;
		//find small(the left side and the right)
		while(small->right != NULL){
			small = small->right;
		}
		val = small->level;
		// change cur->level without changing address
		cur->level = val;
		//delete the original node with the same level as small
		eat_rat(&(cur->left), val);
	}
}

// print preorder for check
/*
void preorder(Node *root){
	if(root != NULL){
		preorder(root->left);
		printf("%d", root->level);
		preorder(root->right);
	}
}
*/
