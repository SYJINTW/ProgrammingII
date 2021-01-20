#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void printInfix(Node *root){
	if(root==NULL)
		return;
	printInfix(root->left);
	printf("%c",root->data);
	if(root->right!=NULL){	
		if(root->right->data=='&'||root->right->data=='|'){
		printf("(");
		printInfix(root->right);
		printf(")");
		}
		else
			printInfix(root->right);
	}
}
