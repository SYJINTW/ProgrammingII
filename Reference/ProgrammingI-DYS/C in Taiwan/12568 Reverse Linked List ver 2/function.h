#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node* next;
} Node;


void Push(Node** ptr_head, int x);
void Pop(Node** ptr_head);
void Reverse_List(Node** ptr_head);

#endif
