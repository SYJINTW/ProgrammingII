#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSYM 6
#define MAXEXPR 256

typedef enum {ID_A,ID_B,ID_C,ID_D,OP_AND,OP_OR}Tokenset;

typedef struct _Node{
	Tokenset data;
	struct _Node *left,*right;
}BTNode;

char sym[MAXSYM] = {'A','B','C','D','&','|'};
char expr[MAXEXPR];
int pos;

void freeTree(BTNode* root);
BTNode* makenode(char c);
BTNode* FACTOR();
BTNode* EXPR();
void printInfix(BTNode *root);

int main(){
	BTNode *root;
	scanf("%s",expr);
	pos = strlen(expr)-1;
	root = EXPR();
	printInfix(root);
	freeTree(root);
	return 0;
}

void freeTree(BTNode* root){
	if(root!=NULL){
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

BTNode* makenode(char c){
	BTNode* node = (BTNode*) malloc(sizeof(BTNode));
	for(int i=0;i<MAXSYM;i++){
		if(c==sym[i]){
			node->data = (Tokenset)i;
			break;
		}
	}
	node->left = NULL;
	node->right = NULL;
	return node;
}

BTNode* FACTOR(){
	char c;
	BTNode *node = NULL;
	if(pos>=0){
		c = expr[pos--];
		if(c>='A'&&c<='D'){
			node = makenode(c);
		}else if(c==')'){
			node = EXPR();
			if(expr[pos--]!='('){
				printf("Error\n");
				freeTree(node);
			}
		}
	}
	return node;
}

BTNode* EXPR(){
	char c;
	BTNode *node = NULL,*right = NULL;
	if(pos>=0){
		right = FACTOR();
		if(pos>0){
			c = expr[pos];
			if(c=='&'||c=='|'){
				node = makenode(c);
				node->right = right;
				pos--;
				node->left = EXPR();
			}else node = right;
		}else node = right;
	}
	return node;
}

void printInfix(BTNode *root){
	if(root!=NULL){
		printInfix(root->left);
		printf("%c",sym[root->data]);
		if(root->right!=NULL){
			if(sym[root->right->data]=='&'||sym[root->right->data]=='|'){
				printf("(");
				printInfix(root->right);
				printf(")");
			}
			else
				printf("%c",sym[root->right->data]);
		}
	}
	return;
}
