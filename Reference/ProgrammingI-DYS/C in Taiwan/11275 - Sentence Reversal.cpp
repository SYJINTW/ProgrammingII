#include<string.h>
#include<stdio.h>
void sentence_reversal( char *now ) {
	int i=0,flag=0;
	while(now[i]!=' '&&now[i]!='\n'){
		i++;
	}
	if(now[i]=='\n'){
		for(int j=0;j<i;j++){
			printf("%c",now[j]);
		}
		return;
	}
	sentence_reversal(now+i+1);
	printf(" ");
	for(int j=0;j<i;j++){
		printf("%c",now[j]);
	}
}
int main(){
	char input[510];
	while(fgets(input,510,stdin)!=NULL){
	sentence_reversal(input);
	printf("\n");}
}
