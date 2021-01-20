#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name[30];
	int occ;
	int age;
}cat;
int cmp(const void * a,const void * b){
	cat A=*(cat *)a;
	cat B=*(cat *)b;
	if(A.occ!=B.occ)	return A.occ>B.occ?1:-1;
	else{
		if(A.age>B.age)	return A.occ==5?1:-1;
		else if(A.age<B.age)	return A.occ==5?-1:1;
		else return strcmp(A.name,B.name);
	}
}
int main(){
	int N,M;
	cat cats[10010];
	char temp[50];
	while(~scanf("%d%d",&N,&M)){
		for(int i=0;i<N;i++){
			scanf("%s%s%d",cats[i].name,temp,&(cats[i].age));
			switch(temp[0]){
				case 'e':
					cats[i].occ=1;
					break;
				case 'n':
					cats[i].occ=2;
					break;
				case 'k':
					cats[i].occ=3;
					break;	
				case 'w':
					cats[i].occ=4;
					break;
				case 'a':
					cats[i].occ=5;
					break;
				case 'm':
					cats[i].occ=6;
					break;
				case 'd':
					cats[i].occ=7;
					break;
				case 'l':
					cats[i].occ=8;
					break;
			}
		}
		qsort(cats,N,sizeof(cat),cmp);
		for(int i=0;i<M&&i<N;i++){
			printf("%s\n",cats[i].name);
		}
	}
} 
