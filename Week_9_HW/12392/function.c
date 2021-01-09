#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "function.h"

#define MAX_N 10004

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

// 找到 return 1, 沒找到 return 0
int query_heatstroke(Node *now, int x){
	// 沒有找到
	if(now == NULL){
		return 0;
	}
	// 找到
	else if(now->level == x){
		return 1;
	}
	// 比要找得值大 => find left
	else if(now->level > x){
		return query_heatstroke(now->left_child, x);
	}
	// 比要找得值小 => find right
	else{
		return query_heatstroke(now->right_child, x);
	}
}

void eat_rat(Node **root, int x){
	if((*root) == NULL) return;
	else;

	// find
	// 比要找得值大 => find left
	if((*root)->level > x){
		eat_rat(&((*root)->left_child), x);
	}
	// 比要找得值小 => find right
	else if((*root)->level < x){
		eat_rat(&((*root)->right_child), x);
	}
	// 找到 -> 吃掉
	else if((*root)->level == x){
		// no child -> 直接吃掉
		if((*root)->left_child == NULL && (*root)->right_child == NULL){
			(*root) = NULL;
			return;
		}
		// left child -> 下一個補上來，吃掉自己
		else if((*root)->right_child == NULL){
			Node *tmp = (*root);
			(*root) = (*root)->left_child;
			free(tmp); 
		}
		// right child -> 下一個補上來，吃掉自己
		else if((*root)->right_child == NULL){
			Node *tmp = (*root);
			(*root) = (*root)->left_child;
			free(tmp); 
		}
		// two child -> 找右邊中的最左邊（剛好比自己大一點）交換值
		else{
			Node *now = (*root)->right_child;
			// find the leftmost side of the right child 
			while(now->left_child != NULL){
				now = now->left_child;
			}
			// change level but don't change address
			(*root)->level = now->level;
			// delete now by using eat_rat from right_child
			eat_rat(&((*root)->right_child), now->level);
		}
	}
}

// 把新加入的那一項存在 tree 的末端
// 如果 x < level 就往 left_child
// 如果 x >= level 就往 right_child
// 直到找到“末端”就建立一個新的 Node
void buy_rat(Node **root, int x){
	// 到末端 -> 建新的 Node
	if((*root) == NULL){
		(*root) = malloc(sizeof(Node));
		(*root)->level = x;
		(*root)->left_child = NULL;
		(*root)->right_child = NULL;	
		return;
	} else;

	// 比要存的值大 -> 往左
	if(x < (*root)->level){
		buy_rat(&((*root)->left_child), x);
	}
	// 比要存的值小 -> 往右
	else{
		buy_rat(&((*root)->right_child), x);
	}
}



