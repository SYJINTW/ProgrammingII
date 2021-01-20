#include<stdio.h>
int main(){
	int n,m,e;
	int x,b[200005]={0},a[200005]{0};
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&e);
		b[i]=e;
		a[e]=1;
	}
	for(int i=m-1;i>=0;i--){
		if(a[b[i]]==1){
			printf("%d\n",b[i]);
			a[b[i]]=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			printf("%d\n",i);
		}
	}
}
