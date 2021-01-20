#include<stdio.h>
#include<string.h>
struct ape{
	char name[15];
	int grade;
	int age;
}ape[1010],temp;

int main(){
	int N,M;
	
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%s%d%d",&ape[i].name,&ape[i].grade,&ape[i].age);
	}	
	for(int i=1;i<N;i++){
		for(int j=N-1;j>=i;j--){
			if(ape[j].grade<ape[j-1].grade){
				temp=ape[j];
				ape[j]=ape[j-1];
				ape[j-1]=temp;
			}
			else if(ape[j].grade==ape[j-1].grade){
				if(ape[j].age>ape[j-1].age){
					temp=ape[j];
					ape[j]=ape[j-1];
					ape[j-1]=temp;
				}
				else if(ape[j].age==ape[j-1].age){
					if(strcmp(ape[j].name,ape[j-1].name)>0){
						temp=ape[j];
						ape[j]=ape[j-1];
						ape[j-1]=temp;
					}
				}
			}
		}
	}
	for(int i=0;i<M;i++){
		printf("%s\n",ape[i].name);
	}
}
