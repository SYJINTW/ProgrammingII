#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int address[25];
int table[25][25];

void sendBook(int bookNum,int to){
	int j;
	for(j=0;table[to][j]!=-1;j++){	}
	table[to][j]=bookNum;
	table[address[bookNum]/100][address[bookNum]%100] = -1;
	address[bookNum]=to*100+j;
}

void returnBookAbove(int a){
	int i;
	for(i = address[a]%100 + 1;table[address[a]/100][i] != -1;i++){
		sendBook(table[address[a]/100][i],table[address[a]/100][i]);
	}
}

void moveonto(int a,int b){
	returnBookAbove(a);
	returnBookAbove(b);
	sendBook(a,address[b]/100);
}

void moveover(int a,int b){
	returnBookAbove(a);
	sendBook(a,address[b]/100);
}

void pileonto(int a,int b){
	returnBookAbove(b);
	int j;
	int ta=address[a]/100;
	for(j = address[a]%100;table[ta][j]!=-1;j++){
		sendBook(table[ta][j],address[b]/100);
	}
}

void pileover(int a,int b){
	int j;
	int ta=address[a]/100;
	for(j = address[a]%100;table[ta][j]!=-1;j++){
		sendBook(table[ta][j],address[b]/100);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		address[i]=i*100;
	}
	
	for(i=0;i<n;i++){
		table[i][0]=i;
		for(j=1;j<n;j++){
			table[i][j]=-1;
		}
	}
	
	char verb[5],prep[5];
	int a,b;
	while(scanf("%s",verb)){
		if(strcmp(verb,"exit")==0){
			break;
		}
		scanf("%d%s%d",&a,prep,&b);
		if(a==b||(address[a]/100)==(address[b]/100)){
			continue;
		}
		if(!strcmp(verb,"move")){
			if(!strcmp(prep,"onto"))
				moveonto(a,b);
			else
				moveover(a,b);
		}
		else if(!strcmp(verb,"pile")){
			if(!strcmp(prep,"onto"))
				pileonto(a,b);
			else
				pileover(a,b);
		}
	}
	for(i=0;i<n;i++){
		printf("%d:",i);
		for(j=0;table[i][j]!=-1;j++){
			printf(" %d",table[i][j]);
		}
		printf("\n");
	}
	return 0;
	
} 
