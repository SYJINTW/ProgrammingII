#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
BTNode* EXPR(){
	char c;
	BTNode *node = NULL,*right = NULL;
	if(pos>=0){
		right = FACTOR();
		if(pos>0){
			c = expr[pos];
			if(c=='&'||c=='|'){
				node = makeNode(c);
				node->right = right;
				pos--;
				node->left = EXPR();
			}else node = right;
		}else node = right;
	}
	return node;
}
BTNode* makeNode(char c){
	BTNode* node = (BTNode*) malloc(sizeof(BTNode));
	int i;
	for(i=0;i<NUMSYM;i++){
		if(c==sym[i]){
			node->data = (TokenSet)i;
			break;
		}
	}
	node->right = NULL;
	node->left = NULL;
	return node;
}
BTNode* FACTOR(){
	BTNode* node;
	char c;
	if(pos>=0){
		c = expr[pos--];
		if(c>='A'&&c<='D'){
			node = makeNode(c);
		}
		else if(c==')'){
			node = EXPR();
			if(expr[pos--]!='('){
				printf("Error\n");
				freeTree(node);
			}
		}
	}
	return node;
}
