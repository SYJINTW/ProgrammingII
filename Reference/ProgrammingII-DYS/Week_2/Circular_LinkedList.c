#include<stdio.h>
#include<stdlib.h>

#define STR_LEN 10
#define STR_EXPAND(tok) #tok
#define STR(tok) STR_EXPAND(tok)

typedef struct t_List{
	int id;
	char name[STR_LEN];
	struct t_List* next;
}List;

typedef struct{
	List* first;
	List* last;
}Head;

List* newData(void);
Head addToFirst(Head head, List* np);
Head addToLast(Head head, List* np);
Head removeFirst(Head head);
Head removeLast(Head head);
void showList(Head head);
Head freeList(Head head);

int main(){
	List* np = NULL;
	Head head;
	head.first = head.last = NULL;
	while((np = newData()) != NULL){
		head = addToLast(head, np);
		showList(head);
	}
	printf("\n");
	printf("Remove First\n");
	head = removeFirst(head);
	showList(head);
	printf("Remove Last\n");
	head = removeLast(head);
	showList(head);

	head = freeList(head);

	return 0;
}

List* newData(void){
	static int ID = 0;
	List* np = (List*)malloc(sizeof(List));
	if(np != NULL){
		printf("Enter a name: ");
		if(scanf("%"STR(STR_LEN)"s", np->name) == 1){
			np->id = ID++;
			np->next = np; //重要
		}
		else{
			free(np);
			np = NULL;
		}
	}
	return np;
}

Head addToFirst(Head head, List* np){
	if(head.first == NULL){
		head.first = head.last = np;
	}
	else{
		np->next = head.first;
		(head.last)->next = np;
		head.first = np;
	}
	return head;
}

Head addToLast(Head head, List* np){
	if(head.first == NULL){
		head.first = head.last = np;
	}
	else{
		np->next = head.first;
		(head.last)->next = np;
		head.last = np;
	}
	return head;
}

Head removeFirst(Head head){
	if(head.first != NULL){
		if(head.first == head.last){
			free(head.first);
			head.first = head.last = NULL;
		}
		else{
			(head.last)->next = (head.first)->next;
			free(head.first);
			head.first = (head.last)->next;
		}
	}
	return head;
}

Head removeLast(Head head){
	List* ptr = (head.first)->next;
	if(head.first != NULL){
		if(head.first == head.last){
			free(head.first);
			head.first = head.last = NULL;
		}
		else{
			while(ptr->next->next != head.first){
				ptr = ptr->next;
			}
			free(head.last);
			head.last = ptr;
			(head.last)->next = head.first;
		}
	}
	return head;
}

void showList(Head head){
	List* ptr = head.first;
	if(head.first != NULL){
		do{
			printf("( %d , %s )->", ptr->id, ptr->name);
			ptr = ptr->next;
		}while(ptr != head.first);
		printf("( %d , %s )\n", ptr->id, ptr->name);
	}	
}

Head freeList(Head head){
	while(head.first != NULL){
		head = removeFirst(head);
	}
	return head;
}
