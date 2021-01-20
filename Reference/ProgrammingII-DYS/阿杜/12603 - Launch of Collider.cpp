#include<stdio.h>
int main(){
	int n,flag=0,pos[200010],time=1000,temp;
	char dir[200010];
	scanf("%d",&n);
	scanf("%s",dir);
	for(int i=0;i<n;i++){
		scanf("%d",&pos[i]);
	}
	for(int i=0;i<n;i++){
		if(dir[i]=='R')
		for(int j=i+1;j<n;j++)
			if(dir[j]=='L'){
				temp=(pos[j]-pos[i])/2;
				break;
			}
		if(temp<time){
			flag=1;
			time=temp;
			}
	}
	if(flag)
		printf("%d\n",time);
	else
		printf("-1\n");
}
