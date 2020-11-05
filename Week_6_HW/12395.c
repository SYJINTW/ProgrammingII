#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 105

char arr[N];
char symbol[] = "+-*/";
int x, y, z;
int len;

typedef struct _Node{
	int type; // 0:operator 1:value 2:variable
	char ch;
	int value;
	struct _Node* left;
	struct _Node* right;
} Node;

void createTree(Node** root){
	static int idx = 0;
	(*root) = (Node*)malloc(sizeof(Node));
	while(arr[idx] != '\0' && isspace(arr[idx])){
		idx++;
	}
	//is_digit
	if(isdigit(arr[idx])){
		int val = 0;
		(*root)->type = 1;
		while(arr[idx] != ' ' && arr[idx] != '\0'){
			val = val*10 + (int)arr[idx] - 48;
			idx++;
		}
		(*root)->value = val;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	//is_value
	else if(arr[idx] == 'x'|| arr[idx] == 'y'|| arr[idx] == 'z'){
		(*root)->type = 2;
		(*root)->ch = arr[idx];
		idx++;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	//is_operator
	else{
		(*root)->type = 0;
		(*root)->ch = arr[idx];
		//printf("%c\n", (*root)->ch);
		idx++;
		createTree(&((*root)->left));
		createTree(&((*root)->right));
	}
}

int cal_t(Node* root){
	int ans = 0;
	if(root == NULL) return -1;
	else;

	//operator
	if(root->type == 0){
		if(root->ch == '+'){
			ans = cal_t(root->left)+cal_t(root->right);
		}
		else if(root->ch == '-'){
			ans = cal_t(root->left)-cal_t(root->right);	
		}
		else if(root->ch == '*'){
			ans = cal_t(root->left)*cal_t(root->right);
		}
		else if(root->ch == '/'){
			ans = cal_t(root->left)/cal_t(root->right);
		}
	}
	//value
	else if(root->type == 1){
		ans = root->value;
	}
	//variable
	else if(root->type == 2){
		if(root->ch == 'x'){
			ans = x;
		}
		else if(root->ch == 'y'){
			ans = y;
		}
		else if(root->ch == 'z'){
			ans = z;
		}
	}
	return ans;
}

void inorder(Node* root){
	if(root == NULL) return;
	else{
		inorder(root->left);
		if(root->type == 0 || root->type == 2) printf("%c", root->ch);
		else printf("%d", root->value);
		inorder(root->right);
	}
}

int main(){
	int result = 0;
	fgets(arr, N, stdin); // 取值到遇到'\n'
	scanf("%d %d %d", &x, &y, &z);
	len = strlen(arr);

	//把最後的 '\n' 換成 '\0'
	if(len > 0 && arr[len-1] == '\n'){
		len--;
		arr[len] = '\0';
	}
	
	Node* root = NULL;
	createTree(&root);
	
	result = cal_t(root);

	inorder(root);
	printf("\n");
	printf("%d\n", result);
	return 0;
}