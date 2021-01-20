#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum node_type{
	OP_AND,OP_OR,ID
}NodeType;
typedef struct node{
    NodeType type;
    int var_id;
    bool eval_value;
    struct node *left;
    struct node *right;
    struct node *parent; //pointing to the parent node
}Node;

Node** var_node; // This array stores the pointers pointing to the tree nodes. For example, variable[0] points to the node with ID number 0.
void construct_syntax_tree(Node** root){
	char input = getchar();
	switch(input){
		case '\n':
			return;
		case '&':
		case '|':
			(*root) = (Node*) malloc(sizeof(Node));
			if(input=='&')
				(*root)->type = OP_AND;
			else
				(*root)->type = OP_OR;
			construct_syntax_tree(&(*root)->left);
			(*root)->left->parent = (*root);
			construct_syntax_tree(&(*root)->right);
			(*root)->right->parent = (*root);
			(*root)->eval_value = false;
			break;
		case '[':
			(*root) = (Node*)malloc(sizeof(Node));
			(*root)->type = ID;
			scanf("%d",&(*root)->var_id);
			var_node[(*root)->var_id] = (*root);
			(*root)->left = NULL;
			(*root)->right = NULL;
			(*root)->eval_value = false;
			
			getchar();
			break;
	}
}

void negate_and_eval(Node* curnode){
	if(curnode->eval_value)
		curnode->eval_value = false;
	else
		curnode->eval_value = true;
	if(curnode->parent==NULL)
		return;
	switch(curnode->parent->type){
		case OP_AND:
			if(curnode->parent->eval_value^(curnode->parent->left->eval_value&curnode->parent->right->eval_value))
				return negate_and_eval(curnode->parent);
			break;
		case OP_OR:
			if(curnode->parent->eval_value^(curnode->parent->left->eval_value|curnode->parent->right->eval_value))
				return negate_and_eval(curnode->parent);
			break;
	}
}

void freeTree(Node *root){
	if(root!=NULL){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	int varNum,flipNum;
	while(T--){
		scanf("%d %d\n",&varNum,&flipNum);
		var_node = (Node**)malloc((varNum+1)*sizeof(Node*));
		Node* root = NULL;
		construct_syntax_tree(&root);
		root->parent = NULL;
		while(flipNum--){
			int id;
			scanf("%d",&id);
			negate_and_eval(var_node[id]);
			printf("%d\n",root->eval_value);
		}
		free(var_node);
		freeTree(root);
	}
}
