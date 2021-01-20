#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "10966.h"

// int main(){
//     return 0;
// }

BTNode* EXPR(){
    char c;
    BTNode* newNode = NULL;
    BTNode* rightNode = NULL;
    if(pos >= 0){
        rightNode = FACTOR();
        if(pos > 0){
            c = expr[pos];
            if(c == '&' || c == '|'){
                newNode = makeNode(c);
                newNode->right = rightNode;
                pos--;
                newNode->left = EXPR();
            }else{
                newNode = rightNode;
            }
        }else{
            newNode = rightNode;
        }
    }
    return newNode;
}
BTNode* FACTOR(){
    char c;
    BTNode* newNode = NULL;

    if(pos >= 0){
        c = expr[pos--];
        if(c >= 'A' && c <= 'D') {
            newNode = makeNode(c);
        }else if(c == ')') {
            newNode = EXPR();
            if(expr[pos--] != '('){
                printf("ERROR\n");
            }
        }
    }
    return newNode;
}
BTNode* makeNode(char c){
    BTNode* newNode = (BTNode*) malloc(sizeof(BTNode));
    // newNode->data = c;
    for(int i=0 ; i<NUMSYM ; ++i){
        if(sym[i] == c){
            newNode->data = i;
            break;
        }
    }
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}