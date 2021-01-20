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


List* newData(void);
List* addToFirst(List* head, List* np);;
List* addToLast(List* head, List* np);
List* removeFirst(List* head);
List* removeLast(List* head);
void showList(List* head);
List* freeList(List* head);

List* newData(void){
	static int ID = 0;
	List* np = (List*)malloc(sizeof(List));	
	
	if(np != NULL){
		printf("Enter a name: ");
		if(scanf("%"STR(STR_LEN)"s", np->name) == 1){
			np->id = ID++;
			np->next = NULL;
		}
		else{
			free(np);
			np = NULL;
		}
	}
	return np;
}	


List* addToFirst(List* head, List* np){
	if(head == NULL){
		head = np;
	}
	else{
		np->next = head;
		head = np;
	}
	return head;
}

List* addToLast(List* head, List* np){
	List* ptr = head;
	if(head == NULL){
		head = np;
	}
	else{
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = np;
	}
	return head;
}

List* removeFirst(List* head){
	List* tmp = head;
	if(head != NULL){
		head = head->next;
		free(tmp);	
	}
	return head;
}

List* removeLast(List* head){
	List* tmp = NULL;
	List* ptr = head;
	if(head == NULL)return NULL;
	else if(head->next == NULL)return NULL;
	else{
		while(ptr->next->next != NULL){
			ptr = ptr->next;
		}
		tmp = ptr->next;
		ptr->next = NULL;
		free(tmp);
		return head;
	}
}

void showList(List* head){
	List* ptr = head;
	while(ptr != NULL){
		printf("( %d , %s )-->", ptr->id, ptr->name);
		ptr = ptr->next;
	}
	printf("////\n");
}


List* freeList(List* head){
	List* tmp;
	/*
	while(head != NULL){
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*/
	while(head != NULL){
		head = removeFirst(head);
	}
	return NULL;
}

int main(){
	List* head = NULL;  //要先把 head 初始化不然會出現 segmentation fault
	List* np = newData();
	
	head = addToFirst(head, np);
	showList(head);

	np = newData();
	head = addToLast(head, np);
	showList(head);
	
	np = newData();
	head = addToFirst(head, np);
	showList(head);
	
	printf("Remove Last\n");	
	head = removeLast(head);
	showList(head);

	printf("Remove First\n");
	head = removeFirst(head);
	showList(head);
	
	head = freeList(head);
	
	return 0;
}

