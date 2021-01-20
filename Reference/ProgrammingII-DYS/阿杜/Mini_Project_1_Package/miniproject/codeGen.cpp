#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codeGen.h"
int r[8],reg_index=0;
extern bool found;
extern int sbcount;
extern getadd(char*);
int evaluateTree(BTNode *root) {
    int retval = 0, lv = 0, rv = 0;

    if (root != NULL) {
        switch (root->data) {
            case ID:
                retval = getval(root->lexeme);
                r[reg_index]=retval;
                printf("MOV r%d [%d]\n",reg_index,getadd(root->lexeme));
                reg_index++;
                break;
            case INT:
                retval = atoi(root->lexeme);  //atoi():covert str to int
                r[reg_index]=retval;
                printf("MOV r%d %d\n",reg_index,retval);
                reg_index++;
                break;
            case ASSIGN:
                rv = evaluateTree(root->right);
                retval = setval(root->left->lexeme, rv);
                printf("MOV [%d] r%d\n",getadd(root->left->lexeme),reg_index-1);
                reg_index--;
                break;
            case ADDSUB:
            case MULDIV:
            case LOGICAL:
                lv = evaluateTree(root->left);
                rv = evaluateTree(root->right);
                if (strcmp(root->lexeme, "+") == 0) {
                    retval = lv + rv;
                    reg_index--;
                    printf("ADD r%d r%d\n",reg_index-1,reg_index);
                } else if (strcmp(root->lexeme, "-") == 0) {
                    retval = lv - rv;
                    reg_index--;
                    printf("SUB r%d r%d\n",reg_index-1,reg_index);
                } else if (strcmp(root->lexeme, "*") == 0) {
                    retval = lv * rv;
                    reg_index--;
                    printf("MUL r%d r%d\n",reg_index-1,reg_index);
                } else if (strcmp(root->lexeme, "/") == 0) {
                    if (rv == 0)
                        error(DIVZERO);
                    retval = lv / rv;
                    reg_index--;
                    printf("DIV r%d r%d\n",reg_index-1,reg_index);
                } else if (strcmp(root->lexeme, "&") == 0) {
                    retval = lv & rv;
                    reg_index--;
                    printf("AND r%d r%d\n",reg_index-1,reg_index);
                } else if (strcmp(root->lexeme, "|") == 0) {
                    retval = lv | rv;
                    reg_index--;
                    printf("OR r%d r%d\n",reg_index-1,reg_index);
                } else if (strcmp(root->lexeme, "^") == 0) {
                    retval = lv ^ rv;
                    reg_index--;
                    printf("XOR r%d r%d\n",reg_index-1,reg_index);
                }
                break;
            case INCDEC:
                retval = evaluateTree(root->right);
                if(strcmp(root->lexeme,"++")==0){
                    retval++;
                    setval(root->right->lexeme,retval);
                    printf("MOV r%d 1\n",reg_index);
                    printf("ADD r%d r%d\n",reg_index-1,reg_index);
                }else{
                    retval--;
                    setval(root->right->lexeme,retval);
                    printf("MOV r%d 1\n",reg_index);
                    printf("SUB r%d r%d\n",reg_index-1,reg_index);
                }
                break;
            default:
                retval = 0;
        }
    }
    return retval;
}

void printPrefix(BTNode *root) {
    if (root != NULL) {
        printPrefix(root->left);
        printPrefix(root->right);
    }
}
