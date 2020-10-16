#include<stdio.h>
#include<stdlib.h>

typedef struct t_Node{
	int data;
	struct t_Node* right;
	struct t_Node* left;
} Node;

int idxSearch(int arr[], int start, int end, int value);
Node* newNode(int val);
Node* constructTree(int inorder[], int preorder[], int inorder_start, int inorder_end);
void inorder(Node *root);
void preorder(Node *root);
void destroy(Node* root);
int maxValue(Node* root);
void writeGV(Node *tree);

//找到 inorder 符合 value 的位置
int idxSearch(int arr[], int start, int end, int value){
	int i;
	for(i = start; i <= end; i++){
		if(arr[i] == value) return i;
		else;
	}
	return -1;
}

Node* newNode(int val){
	Node* root = (Node*)malloc(sizeof(Node));
	//建成功或是失敗
	if(root != NULL){
		root->data = val;
		root->left = NULL;
		root->right = NULL;
	} else;

	return root;
}

Node* constructTree(int inorder[], int preorder[], int inorder_start, int inorder_end){
	static int preorder_idx = 0;
	int i;

 	if(inorder_start > inorder_end) return NULL;
 	else;

 	Node* tree_node = newNode(preorder[preorder_idx]);
 	preorder_idx++;

 	if(inorder_start == inorder_end) return tree_node;
 	else;

 	i = idxSearch(inorder, inorder_start, inorder_end, tree_node->data);
 	tree_node->left = constructTree(inorder, preorder, inorder_start, i-1);
 	tree_node->right = constructTree(inorder, preorder, i+1, inorder_end);

 	return tree_node;
}

void inorder(Node *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	} else;
}

void preorder(Node *root){
	if(root != NULL){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int maxValue(Node* root){
	if(root != NULL){
		int max = root->data;
		int value;
		if(root->left != NULL){
			value = maxValue(root->left);
			if(value > max) max = value;
			else;
		} else;

		if(root->right != NULL){
			value = maxValue(root->right);
			if(value > max) max = value;
			else;
		} else;

		return max;
	}
	else return -1;
}

void destroy(Node* root){
	if(root != NULL){
		destroy(root->left);
		destroy(root->right);
		free(root);
	} else;
}

//Output tree.gv for graphviz
void printTree(FILE *fout, Node *tree){
    if (tree!=NULL) {
        if (tree->left!=NULL)
            fprintf(fout, "%d -> %d;\n", tree->data, tree->left->data);
        if (tree->right!=NULL)
            fprintf(fout, "%d -> %d;\n", tree->data, tree->right->data);
        printTree(fout, tree->left);
        printTree(fout, tree->right);
    }
}

void writeGV(Node *tree){
    FILE *fout = fopen("tree.gv", "w");
    fprintf(fout, "digraph T {\n");
    printTree(fout, tree);
    fprintf(fout, "}\n");
}

int main(){
	//Construct a Tree by inorder_list and preorder_list
	int n;
	scanf("%d", &n);
	int* in = (int*)malloc(sizeof(int)*n);
	int* pre = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++){
		scanf("%d", in+i);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", pre+i);
	}
	Node* root = constructTree(in, pre, 0, n-1);
	
	//Output for graphviz
	writeGV(root);

	//Output tree
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	printf("%d\n", maxValue(root));

	//Clean memory
	destroy(root);
	free(in);
	free(pre);

	//Create a Tree by hand
	/*
	Node* root = newNode(2);
	root->left = newNode(7);
	root->left->left = newNode(3);
	root->left->right = newNode(6);
	root->left->right->left = newNode(8);
	root->left->right->right = newNode(11);	
	root->right = newNode(5);
	root->right->right = newNode(9);
	root->right->right->right = newNode(4);

	inorder(root);
	printf("\n");
	preorder(root);
	*/
	return 0;
}

/*
9
3 7 8 6 11 2 5 9 4
2 7 3 6 8 11 5 9 4
*/













