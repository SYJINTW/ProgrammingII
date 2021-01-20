#include<stdio.h>
int n, flag=0;
char chess[110][110],ans[11]="ICPCASIASG";
void ok(int pos,int num){
	if(num==10){
		flag=1;
		return;
	}
	else{for(int i=-2;i<=2;i++){
		for(int j=-2;j<=2;j++){
			if(i*i+j*j!=5||pos/n+i<0||pos/n+i>=n||pos%n+j>=n||pos%n+j<0)
				continue;
			if(chess[pos/n+i][pos%n+j]==ans[num])
				ok(pos+i*n+j,num+1);
		}
	}
	}
	return;
}
int main(){
	int now=0;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%c",&chess[i][j]);
	while(now<n*n&&!flag){
		if(chess[now/n][now%n]==ans[0])	ok(now,1);
		now++;
	}
	printf("%s\n",(flag?"YES":"NO"));
}
