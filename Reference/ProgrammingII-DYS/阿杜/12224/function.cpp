#ifndef function_h
#define function_h
#include <cstddef>
#include <iostream>

class ListNode {
private:
    int data;
    ListNode* next;
    ListNode* prev;
public:
    ListNode() :data(0), next(nullptr), prev(nullptr) {};
    ListNode(int a) :data(a), next(nullptr), prev(nullptr) {};

    friend class List;
};

class List {
private:
    ListNode* head;  // head of the doubly linked list
    ListNode* tail;  // tail of the doubly linked list
    ListNode* middle; // middle of the list
    int       cnt;   // total count of the elements in the list
    int       pos;   // the position of middle (0 means no middle, so pos starts from 1)

    void reset() {
        head = nullptr;
        tail = nullptr;
        middle = nullptr;
        cnt = 0;
        pos = 0;
    }

    void clean() {
        ListNode* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    // constructor and destructor
    List() {
        reset();
    }

    ~List() {
        clean();
    }

    // Declaration of class methods.
    void InsertHead(int data);
    int  RemoveHead();
    void InsertTail(int data);
    int  RemoveTail();
    void Swap();
    // The following four functions are used for debug.
    int  getSize(); // Included in the original header, but not necessary.
    int  getMiddle(); // Included in the original header, but not necessary.
    int  getHead(); // Not included in the original header.
    int  getTail(); // Not included in the original header.
    // You can modify the main function to use these debug commands.


};

void List::InsertHead(int data){
    ListNode* newhead = new ListNode;
    newhead->data = data;
    newhead->next = head;
    newhead->prev = nullptr;
    if(head!=nullptr) head->prev = newhead;
    if(cnt==0){
        head = newhead;
        tail = newhead;
        middle = newhead;
        pos++;
        cnt++;
        return;
    }
    head = newhead;
    cnt++;
    pos++;
    if(cnt/2+1<pos){
        pos--;
        middle = middle->prev;
    }
}
int  List::RemoveHead(){
    if(cnt==0)throw std::out_of_range("\n");
    cnt--;
    pos--;
    if(cnt/2+1<pos){
        pos--;
        middle = middle->prev;
    }

    ListNode* oldhead = head;
    int olddata = oldhead->data;
    head = head->next;
    if(head!=nullptr) head->prev = nullptr;
    delete oldhead;
    if(cnt==0) reset();
    return olddata;
}
void List::InsertTail(int data){
    ListNode* newtail = new ListNode;
    newtail->data = data;
    newtail->next = nullptr;
    newtail->prev = tail;
    if(tail!=nullptr) tail->next = newtail;
    if(cnt==0){
        head = newtail;
        middle=newtail;
        tail=newtail;
        cnt++;
        pos++;
        return;
    }
    tail = newtail;
    cnt++;
    if(cnt/2+1>pos){
        pos++;
        middle = middle->next;
    }
}
int  List::RemoveTail(){
    if(tail==nullptr) throw std::out_of_range("\n");
    cnt--;
    if(cnt/2+1<pos){
        pos--;
        middle = middle->prev;
    }
    ListNode* oldtail = tail;
    int olddata = oldtail->data;
    tail = tail->prev;
    if(tail!=nullptr) tail->next = nullptr;
    delete oldtail;
    if(cnt == 0) reset();
    return olddata;
}
void List::Swap(){
    if(cnt==0||cnt==1) return;
    ListNode* oldhead = head;
    ListNode* oldtail = tail;
    ListNode* oldmiddle = middle;
    head = oldmiddle;
    tail = oldmiddle->prev;

    oldtail->next = oldhead;
    oldhead->prev = oldtail;
    head->prev = nullptr;
    tail->next = nullptr;
    if(cnt%2==0)    pos--;
    middle = oldtail;
    if(cnt/2+1>pos){
        pos++;
        middle = middle->next;}
}



#endif
