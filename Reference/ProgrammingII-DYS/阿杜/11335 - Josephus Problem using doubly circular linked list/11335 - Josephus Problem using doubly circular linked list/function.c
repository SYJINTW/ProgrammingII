#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct _Node{
    int number;
    struct _Node* next;
    struct _Node* prev;
}Node;

typedef enum _State{
    Forward,Backward
}State;

Node* head;

Node* createList(int n){
    Node* head = (Node*)malloc(sizeof(Node));
    Node* prevNode = head;
    for(int i=1;i<=n;i++){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->number = i;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        prevNode = prevNode->next;
    }
    prevNode->next = head->next;
    head->next->prev = prevNode;
    prevNode = head;
    head = head->next;
    free(prevNode);
    return head;
}

void freeList(){
    return;
}

int solveJosephus(int step){
    int distance = step;
    State curState = Forward;
    Node* curNode = head;
    while(curNode->next != curNode){
        if(distance==1){
            curNode->prev->next = curNode->next;
            curNode->next->prev = curNode->prev;
            distance = step;
            Node* temp;
            switch(curState){
                case Forward:
                    temp = curNode;
                    curNode = curNode->prev;
                    free(temp);
                    curState = Backward;
                    break;
                case Backward:
                    temp = curNode;
                    curNode = curNode->next;
                    free(temp);
                    curState = Forward;
                    break;
            }
        }
        else{
            distance--;
            switch(curState){
                case Forward:
                    curNode = curNode->next;
                    break;
                case Backward:
                    curNode = curNode->prev;
                    break;
            }
        }
    }
    int ans = curNode->number;
    free(curNode);
    return ans;
}
#endif // FUNCTION_H
