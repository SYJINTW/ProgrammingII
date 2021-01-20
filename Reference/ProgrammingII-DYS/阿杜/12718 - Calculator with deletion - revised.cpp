#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
	char type;
	long long value;
	int size;
	struct _node *left,*right,*parent;
}Node;

char expr[300010];
int pos=0;
Node *root;
Node *array[300010];

Node *buildTree(){
	Node *root;
	char c = getchar();
	expr[pos++] = c;
	root = (Node*)malloc(sizeof(Node));
	root->type = c;
	root->left = root->parent = root->right = NULL;
	root->size = 1;
	root->value = 0;
	
	array[pos] = root;
	
	if(c=='+'||c=='*'||c=='-'){
		root->left = buildTree();
		root->left->parent = root;
		root->right = buildTree();
		root->right->parent = root;
		root->size = root->size + root->left->size + root->right->size;
	}
	else{
		root->value = (int)c-'0';
		return root;
	}
	return root;
}

long long Q_A(Node *root){
	if(root->type=='+'){
		return root->value = (Q_A(root->left) + Q_A(root->right))%10007;
	}
	else if(root->type=='-'){
		return root->value = (Q_A(root->left) - Q_A(root->right))%10007;
	}
	else if(root->type=='*'){
		return root->value = (Q_A(root->left)*Q_A(root->right))%10007;
	}
	else{
		return root->value;
	}
}

void evaluatefrom(Node *cur){
	if(cur==NULL)return;
	if(cur->type=='+')
		cur->value = (cur->left->value + cur->right->value)%10007;
	else if(cur->type=='-')
		cur->value = (cur->left->value - cur->right->value)%10007;
	else if(cur->type=='*')
		cur->value = (cur->left->value * cur->right->value)%10007;
	evaluatefrom(cur->parent);
}

void D(int l,int r){
	int tmpSize = root->size;
	int curSize = 0, curIndex = 0, indexToBeConnect = r+1;
	for(int i=l;i<=r;i++){
		if(array[i]->size>curSize){
			curSize = array[i]->size;
			curIndex = i;
		}
	}
	
	array[indexToBeConnect]->parent = array[curIndex]->parent;
	
	if(array[curIndex]->parent!=NULL){
		if(array[curIndex]->parent->left==array[curIndex])
			array[curIndex]->parent->left = array[indexToBeConnect];
		else
			array[curIndex]->parent->right = array[indexToBeConnect];
			
		Node *tmp = array[curIndex]->parent;
		
		while(tmp!=NULL){
			tmp->size -= (r-l)+1;
			tmp = tmp->parent;
		}
	}
	else{
		root = array[indexToBeConnect];
	}
	for(int i = 0;r+1+i<=tmpSize;i++){
		array[l+i] = array[r+1+i];
	}
	if(array[indexToBeConnect]->parent!=NULL){
		evaluatefrom(array[indexToBeConnect]->parent);
	}
}

int main(){
	int T,num1,num2;
	char DQ[10];
	scanf("%d\n",&T);
	root = buildTree();
	Q_A(root);
	while(T--){
		scanf("%s",DQ);
		if(DQ[0]=='Q'){
			scanf("%d",&num1);
			printf("%lld\n",(array[num1]->value)%10007);
		}
		else if(DQ[0]=='D'){
			scanf("%d %d",&num1,&num2);
			D(num1,num2);
		}
	}
}
