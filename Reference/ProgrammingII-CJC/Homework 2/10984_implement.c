#include <stdio.h>
#include <stdlib.h>
#include "10984.h"

void constructTree(Node** head){
    char c = getchar();
    *head = (Node*) malloc(sizeof(Node));
    // if(c == '\n')
    //     return;
    if(c == '|' || c == '&'){
        (*head)->data = c;
        constructTree(&(*head)->left);
        constructTree(&(*head)->right);
    }else if(c >= 'A' && c <= 'D'){
        (*head)->data = c;
        (*head)->left = (*head)->right = NULL;
    }
}

