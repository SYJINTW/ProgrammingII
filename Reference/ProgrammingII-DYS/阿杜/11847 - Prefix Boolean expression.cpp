#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node{
	char value;
	struct _Node *left,*right;
}Node;

Node *makenode(char value){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node *build(){
	char c;
	scanf("%c",&c);
	Node *node = NULL;
	if(c=='&'||c=='|'){
		node = makenode(c);
		node->left = build();
		node->right = build();
	}
	else
		node = makenode(c);
	return node;
}

int solve(Node *head,int v){
	if(head->value == '&')
		return solve(head->left,v)&solve(head->right,v);
	else if(head->value=='|'){
		return solve(head->left,v)|solve(head->right,v);
	}
	else
		return (v>>(3-(head->value - 'A')))&1;
}

int main(){
	Node* root = NULL;
	root = build();
	for(int i=0;i<16;i++){
		printf("%d %d %d %d %d\n",(i>>3)&1,(i>>2)&1,(i>>1)&1,i&1,solve(root,i));
	}
}
