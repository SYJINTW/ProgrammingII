#include<stdio.h>
int height[10010]={0},ans[10010]={0},level[10010]={0};
int main(){
	int i,j,N,goal,cnt=0,flag=0;
	scanf("%d%d",&N,&goal);
	for(i=1;i<=N;i++){
		scanf("%d",&height[i]);
		for(j=i-1;j>=1;){
			if(height[i]>height[j]){
				j=j-level[j]-1;
			}
			else
				break;
		}
		level[i]=i-j-1;
		if(level[i]==goal){
			ans[cnt++]=i;
		}
	}
	for(int k=0;k<cnt;k++){
		if(flag)
			printf(" ");
		printf("%d",ans[k]);
		flag=1;
	}
	if(flag)
		printf("\n");
	else
		printf("ouo\n");
}
