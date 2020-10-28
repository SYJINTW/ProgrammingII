#include <stdio.h>
#include <stdlib.h>
#define NUM 1000000009

typedef struct t_Node{
	int id, num;
	struct t_Node* left;
	struct t_Node* right;
} Node;

int order[NUM];

void build_tree(Node **now, int *arr, int l, int r) {
	if(l>r) return;
	Node* root = (*now);
	root = (Node*)malloc(sizeof(Node));
	if(l==r) {
		root->id = l;
		root->num = arr[l];
		root->left = NULL;
		root->right = NULL;
	}
	else {
		int mid = (l+r)/2;
		root->id = mid;
		root->num = arr[mid];
		build_tree(&(root->left), arr, l, mid-1);
		build_tree(&(root->right), arr, mid+1, r);
	}
	*now = root;
}

int search(Node *now, int x) {
    if(now==NULL) return 0;
	else;

	if(now->num == x) return now->id;
	else if(now->num > x) return search(now->left, x);
	else return search(now->right, x);
}


void freeBST(Node *root){
    if(root == NULL) return;
	else;
	freeBST(root->left);
	freeBST(root->right);
	free(root);
}

int main(){
	int n, q;
	int search_value, search_index;

	while(scanf("%d %d", &n, &q) != EOF){
		for(int i = 0; i < NUM; i++){
			order[i] = 0;
		}

		for(int i = 1; i <= n; i++){
			scanf("%d", &order[i]);
		}
		Node* tree = NULL;
		build_tree(&tree, order, 1, n);
		while(q--){
			scanf("%d", &search_value);
			search_index = search(tree, search_value);
			if(search_index){
				printf("%d\n", search_index);
			}
			else{
				printf("Break your bridge!\n");
			}
		}
		freeBST(tree);
	}

}


//Compile Error