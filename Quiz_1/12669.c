#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node{
	char val;
	struct _Node* next;
} Node;

int main(){
	int n, k;
	char c;
	Node* hp = NULL, np = NULL;
	scanf("%d", &n);
	while(n--){
		hp = NULL;
		scanf("%d", &k);
		while(n--){
			scanf("%c", &c);
			if(c >= 'a' && c <= 'z'){
				
				if(hp == NULL){

				}
			}
			else if(c == B){

			}
		}
	}	
}