/* This program construct a syntax tree from an infix Boolean expression.
   The expression has no parenthesis, and no error checking.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXEXPR 256
#define NUMSYM 6
char expr[MAXEXPR];

typedef enum {VAR_A, VAR_B, VAR_C, VAR_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM]="ABCD&|";

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

/* create a node without any child.*/
BTNode* makeNode(char c){
    int i;
    BTNode *node = (BTNode*) malloc(sizeof(BTNode));
    for (i = 0; i< NUMSYM; i++)
        if (c==sym[i])
        {
            node->data = i;
            break;
        }
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

/* print a tree by in-order. */
void printInfix(BTNode *root){
    if (root != NULL) {
        printInfix(root->left);
        printf("%c",sym[root->data]);
        printInfix(root->right);
    }
}

/* parse a prefix expression and generate a syntax tree. */
/* Grammar: prefix := VAR | OP <prefix> <prefix> */
BTNode* pre_parser()
{
   int i;
   BTNode *node;
   static pos=0; // a static variable to remember the current position in the expr[]

   if (expr[pos]>='A' && expr[pos]<='D') // prefix = ID
      return makeNode(expr[pos++]);
   else            // prefix = OP <prefix> <prefix>
   {
      node = makeNode(expr[pos++]);
      node->left = pre_parser();
      node->right = pre_parser();

      return node;
   }
}

int main(){
    gets(expr);
    BTNode *root = pre_parser();
    printInfix(root);
    freeTree(root);
    return 0;
}
