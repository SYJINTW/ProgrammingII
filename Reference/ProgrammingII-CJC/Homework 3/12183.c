#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

// typedef enum node_type {
// 	OP_AND, OP_OR, ID
// } NodeType;

typedef struct _Node{
    // NodeType type;
	// For variable nodes.
	// int var_id;
    char c;
	// The boolean value the node's expression evaluates to. Initialized as false.
	bool eval_value;
    struct _Node* left;
    struct _Node* right;
    struct _Node* parent;
} Node;

Node** NodePtr;

void constructTree(Node** curNode);
void printTree(Node* curNode);
void reCal(Node* curNode);
void freeTree(Node* curNode);

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int N, M;
        scanf("%d %d\n", &N, &M);

        NodePtr = (Node**)malloc((N+1) * sizeof(Node*));

        Node* root = NULL;
        constructTree(&root);
        if(root)
            root->parent = NULL;
        int i=0;
        for( i=0 ; i<M ; ++i){
            int num;
            scanf("%d", &num);
            NodePtr[num]->eval_value = !NodePtr[num]->eval_value;
            reCal(NodePtr[num]->parent);
            printf("%d\n", root->eval_value);
        }
        free(NodePtr);
        freeTree(root);
    }
    return 0;
}

void constructTree(Node** curNode){
    char ch = getchar();
    switch(ch){
        case '\n':
            return;
        case '|':
        case '&':
            (*curNode) = (Node*)malloc(sizeof(Node));
            // -----
            // if(ch == '&') (*curNode)->type = OP_AND;
            // else (*curNode)->type = OP_OR;
            // -----
            (*curNode)->c = ch;
            constructTree(&(*curNode)->left);
            (*curNode)->left->parent = (*curNode); //?
            constructTree(&(*curNode)->right);
            (*curNode)->right->parent = (*curNode); //?
            (*curNode)->eval_value = false;
            break;
        case '[':
            
            (*curNode) = (Node*)malloc(sizeof(Node));
            // -----
            // (*curNode)->type = ID;
            // -----
            // *****Problem is as following*****: 
            // 白癡喔兩位數以上阿幹，腦殘?

            int index;
            scanf("%d", &index);
            NodePtr[index] = (*curNode);
            (*curNode)->c = index + '0';

            // char index_c;
            // scanf("%c", &index_c);
            // NodePtr[(index_c + '0')] = (*curNode);
            // (*curNode)->c = index_c;
            
            (*curNode)->left = NULL;
            (*curNode)->right = NULL;
            (*curNode)->eval_value = false;
            

            getchar();
            break;
    }
}

void printTree(Node* curNode){
    if(!curNode)
        return;
    printf("%c ", curNode->c);
    printTree(curNode->left);
    printTree(curNode->right);
}

void reCal(Node* curNode){
    if(!curNode)
        return;
    if(curNode->c == '|'){
        bool newValue = curNode->left->eval_value | curNode->right->eval_value;
        if(newValue == curNode->eval_value)
            return;
        else{
            curNode->eval_value = newValue;
            reCal(curNode->parent);
        }
    }else if(curNode->c == '&'){
        bool newValue = curNode->left->eval_value & curNode->right->eval_value;
        if(newValue == curNode->eval_value)
            return;
        else{
            curNode->eval_value = newValue;
            reCal(curNode->parent);
        }
    }else{
    	
    }
}

void freeTree(Node* curNode){
    if(!curNode)
        return;
    freeTree(curNode->left);
    freeTree(curNode->right);
    free(curNode);
}
