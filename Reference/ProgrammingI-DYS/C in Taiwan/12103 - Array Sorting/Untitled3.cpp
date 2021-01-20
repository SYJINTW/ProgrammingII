#include<stdio.h>
int main(){
	int a[10000010],b[10000010];
	int N,level;
	scanf("%d%d",&N,&level);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=N;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i]<=a[j])
				break;
			b[i]++;
		}
	}
	int flag=0;
	for(int i=1;i<=N;i++){
		if(b[i]==level){
			if(flag)
				printf(" ");
			printf("%d")
			flag=1;
		}
	}
	if(!flag)
		printf("ouo\n");
}
