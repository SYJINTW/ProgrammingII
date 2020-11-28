#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX_N 10004

typedef struct _NODE {
	int level;
	struct _NODE *left_child, *right_child;
} Node;

void build_tree(Node **now, int *arr, int l, int r){
	if(l > r){
		(*now) = NULL;
		return;
	} else;

	int mid = (l+r)/2;
	(*now) = malloc(sizeof(Node));
	(*now)->level = arr[mid];
	build_tree(&((*now)->left_child), arr, l, mid-1);
	build_tree(&((*now)->right_child), arr, mid+1, r);	
}


int query_heatstroke(Node *now, int x){
	if(now == NULL) return 0;
	else;

	if(now->level == x){
		return 1;
	}
	else if(now->level > x){
		return query_heatstroke(now->left_child, x);
	}
	else{
		return query_heatstroke(now->right_child, x);
	}
}

void eat_rat(Node **root, int x){
	if((*root) == NULL) return;
	else;

	// find
	if((*root)->level > x){
		eat_rat(&((*root)->left_child), x);
	}
	else if((*root)->level < x){
		eat_rat(&((*root)->right_child), x);
	}
	else if((*root)->level == x){
		// no child
		if((*root)->left_child == NULL && (*root)->right_child == NULL){
			(*root) = NULL;
			return;
		}
		// left child
		else if((*root)->right_child == NULL){
			Node *tmp = (*root);
			(*root) = (*root)->left_child;
			free(tmp); 
		}
		// right child
		else if((*root)->right_child == NULL){
			Node *tmp = (*root);
			(*root) = (*root)->left_child;
			free(tmp); 
		}
		// two child
		else{
			Node *now = (*root)->right_child;
			while(now->left_child != NULL){
				now = now->left_child;
			}
			// change level but don't change address
			(*root)->level = now->level;
			// delete now by using eat_rat
			eat_rat(&((*root)->right_child), now->level);
		}
	}
}

// 把新加入的那一項存在 tree 的末端
// 如果 x < level 就往 left_child
// 如果 x >= level 就往 right_child
// 直到找到“末端”就建立一個新的 Node
void buy_rat(Node **root, int x){
	if((*root) == NULL){
		(*root) = malloc(sizeof(Node));
		(*root)->level = x;
		(*root)->left_child = NULL;
		(*root)->right_child = NULL;	
		return;
	} else;

	if(x < (*root)->level){
		buy_rat(&((*root)->left_child), x);
	}
	else{
		buy_rat(&((*root)->right_child), x);
	}
}



