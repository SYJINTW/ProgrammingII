#include<stdio.h>
int min(int x,int y);
int main(){
	int n,m,time,T,j,k;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d %d %d",&n,&m,&time);
		for(j=0;j<(time-m)%n;j++){
			printf("-");
		}
		if(time<n){
			for(k=0;k<min(time,m);k++){
				printf("^");
			}
		}
		else{
			for(k=0;k<n+m-time;k++){
				printf("^");
			}
		}
		while(j+k<n){
			printf("-");
			k++;
		}
		printf("\n");
	}
}
int min(int x,int y){
	if(x>=y)
		return y;
	else
		return x;
} 
