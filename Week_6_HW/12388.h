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
	Node* now = *root;
	Node* tmp = NULL;
	if(now == NULL) return;
	if(x == now->level){
		if(now->left == NULL && now->right == NULL){
			tmp = now;
			now = NULL;
			free(tmp);
		}
		else if(now->left == NULL){
			//half leaf with left NULL
			tmp = now;
			now = now->right;
			free(tmp);
		}
		else if(now->right == NULL){
			//half leaf with right NULL
			tmp = now;
			now = now->left;
			free(tmp);
		}
		else{
			//find the most right in the left
			Node* lr = now->left;
			Node* lr_prev = now;
			while(lr->right != NULL){
				lr_prev = lr;
				lr = lr->right;
			}
			//delete
			tmp = now;
			now = lr;
			lr_prev->right = NULL;
			free(tmp);
		}
	} 
	else if(x < now->level){
		eat_rat(&(now->left), x); // find left
	}
	else if(x > now->level){
		eat_rat(&(now->right), x); // find right
	}
	*root = now;
}
