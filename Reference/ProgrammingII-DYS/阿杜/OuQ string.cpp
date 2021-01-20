#include<stdio.h>
long long l,r;
long long length[55];
char s1[5]="OuQ";

char askingchar(int k,long long num){
	if(k==1)
		return s1[num];
	if(num==0)
		return 'O';
	else if(num==length[k]-1)
		return 'Q';
	else if(num==length[k-1]+1)
		return 'u';
	else{
		if(num<length[k-1]+1)
			return askingchar(k-1,num-1);
		else
			return askingchar(k-1,num-length[k-1]-2);
	}
}

int main(){
	int k;
	length[1]=3;
	
	for(int i=2;i<=53;i++)		length[i]=length[i-1]*2+3;
	
	while(~scanf("%d %lld %lld",&k,&l,&r)){
		for(int i=l;i<=r;i++)
			printf("%c",askingchar(k,i));
		printf("\n");
	}
}
