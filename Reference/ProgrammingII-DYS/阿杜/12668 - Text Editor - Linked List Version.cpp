#include<stdio.h>
#include<stdlib.h>
int N;
char str[1000010];
typedef struct node{
	char data;
	struct node *prev;
	struct node *next;
}Node;
int main(){
	int T;
	char c;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		Node *head=(Node*)malloc(sizeof(Node));
		head->next=NULL;
		head->prev=NULL;
		Node* now=head;
		Node*p;
		for(int i=0;i<N;i++){
			scanf("%c",&c);
			switch(c){
				case 'L':
					now=now->prev;
					break;
				case 'B':
					p=now;
					now=now->prev;
					now->next=p->next;
					p->next->prev=now;
					free(p);
					break;
				case 'R':
					now=now->next;
					break;
				default:
					p=(Node*)malloc(sizeof(Node));
					p->data=c;
					if(now->next!=NULL){
						p->next=now->next;
						(now->next)->prev=p;
						now->next=p;
						p->prev=now;
					}
					else{
						now->next=p;
						p->next=NULL;
						p->prev=now;
					}
					now=now->next;
			}
		}
		Node *a=head;
		
		while(a->next!=NULL){
			printf("%c",a->data);
			a=a->next;
		}
		while(head->next!=NULL){
			Node *d=head;
			head=head->next;
			free(d);
		}
		printf("\n");
	}
	return 0;
}
