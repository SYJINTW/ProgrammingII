#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
    int data;
    int depth;
    struct _Node* left;
    struct _Node* right;
}Node;

void insert(Node* curNode, Node* insertNode);
void P(Node* curNode);
int getMax(Node** BST, int N);
int sumLevel(int level, Node** BST, int N);
float avgLevel(int level, Node** BST, int N);

int main(){
    int N = 0;
    scanf("%d", &N);

    Node* BST[100];
    for(int i=0 ; i<100 ; ++i){
        // Why I must allocate storage here or testcase 2 will runtime error?
        // Set BST[0]->depth = 1 below = =
    }
    for(int i=0 ; i<N ; ++i){
        BST[i] = (Node*)malloc(sizeof(Node));

        int d;
        scanf("%d", &d);
        BST[i]->data = d;
        BST[i]->left = NULL;
        BST[i]->right = NULL;
    }

    if(BST[0]){
        BST[0]->depth = 1;
        for(int i=1 ; i<N ; ++i){
            insert(BST[0], BST[i]);
        }
    }

    int maxH = getMax(BST, N);

    int M;
    scanf("%d", &M);
    for(int i=0 ; i<M ; ++i){
        int level;

        char str[20];
        scanf("%s", str);
        switch (str[0])
        {
        case 'A':
            scanf("%d", &level);
            if(level > maxH || level == 0) //for testcase 4, level == 0, print "0"
                printf("0\n");
            else
                printf("%.3f\n", avgLevel(level, BST, N));
            break;
        case 'S':
            scanf("%d", &level);
            if(level > maxH || level == 0) //for testcase 4, level == 0, print "0"
                printf("0\n");
            else
                printf("%d\n", sumLevel(level, BST, N));
            break;
        case 'P':
            if(N == 0)
                printf("NULL");
            else
                P(BST[0]);
            printf("\n");
            break;
        case 'G':
            printf("%d\n", maxH);
            break;
        default:
            printf("ERROR\n");
            break;
        }
    }

    return 0;
}

void insert(Node* curNode, Node* insertNode){
    if(insertNode->data > curNode->data){
        if(curNode->right == NULL){
            curNode->right = insertNode;
            insertNode->depth = curNode->depth + 1;
        }
        else
            insert(curNode->right, insertNode);
    }else if(insertNode->data < curNode->data){
        if(curNode->left == NULL){
            curNode->left = insertNode;
            insertNode->depth = curNode->depth + 1;
        }
        else
            insert(curNode->left, insertNode);
    }else{

    }
}

void P(Node* curNode){
    if(curNode == NULL)
        return;
    P(curNode->left);
    printf("%d ", curNode->data);
    P(curNode->right);
}

int getMax(Node** BST, int N){
    int curMax = 0;
    for(int i=0 ; i<N ; ++i){
        if(BST[i]->depth > curMax)
            curMax = BST[i]->depth;
    }
    return curMax;
}

int sumLevel(int level, Node** BST, int N){
    int curSum = 0;
    for(int i=0 ; i<N ; ++i){
        if(BST[i]->depth == level)
            curSum += BST[i]->data;
    }
    return curSum;
}

float avgLevel(int level, Node** BST, int N){
    float curSum = 0.0f;
    int number = 0;
    for(int i=0 ; i<N ; ++i){
        if(BST[i]->depth == level){
            curSum += BST[i]->data;
            number++;
        }       
    }
    return curSum/number;
}