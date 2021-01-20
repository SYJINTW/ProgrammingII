#include "11371.h"
#include <stdlib.h>
#include <stdio.h>

void printNode(Node* head) {
    while (head != NULL) {
        if(head->data != 0){
            printf(" %ld %d", head->data, head->power);
        }
        head = head->next;
    }
    // printf("\n");
}

Node* create() {
    Node* head = NULL, *prevNode = NULL;

    long coefficient;
    int power;
    while(scanf("%ld %d", &coefficient, &power)) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = coefficient;
        newNode->power = power;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            prevNode = newNode;
        } else {
            prevNode->next = newNode;
            newNode->prev = prevNode;
            prevNode = prevNode->next;
        }

        if(power == 0)
            break;
    }

    return head;
}

void destroy(Node *node) {
    if (node != NULL) {
        destroy(node->next);
        free(node);
    }
}

Node* multiple(Node* p1, Node* p2) {
    // Node* head = NULL;
    Node* head = (Node*) malloc (sizeof(Node));
    head->power = -1;
    head->prev = NULL;
    head->next = NULL;

    Node* toBeDeleted = head;

    for (Node* temp1 = p1; temp1 != NULL; temp1 = temp1->next) {
        for (Node* temp2 = p2; temp2 != NULL; temp2 = temp2->next) {
            long new_coeff = temp1->data * temp2->data;
            int new_power = temp1->power + temp2->power;

            if(new_coeff == 0)
                continue;
            for (Node* n = head; n != NULL; n = n->next) {
                if(new_power > n->power) {
                    Node* newNode = (Node*) malloc(sizeof(Node));
                    newNode->data = new_coeff;
                    newNode->power = new_power;

                    newNode->next = n;
                    newNode->prev = n->prev;

                    if(n->prev != NULL)
                        n->prev->next = newNode;
                    else
                        head = newNode;
                    n->prev = newNode;
                    break;
                }
                else if (new_power == n->power) {
                    n->data += new_coeff;
                    break;
                }
            }
        }
    }
    if(toBeDeleted->prev)
        toBeDeleted->prev->next = NULL;
    else 
        head = NULL;
    free(toBeDeleted);

    return head;
}