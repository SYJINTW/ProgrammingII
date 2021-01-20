#include<stdio.h>
int main(){
	int a[2010],t,b[2010],N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++){
		b[i]=a[i];
	}
	for(int i=0;i<N;i++){
		for(int j=1;j<N-i;j++){
			if(a[j]<a[j-1]){
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(int i=0;i<N;i++){
		if(i!=N-1){
			for(int j=0;j<N;j++){
				if(b[i]==a[j]){
					printf("%d ",j+1);
					break;
				}
			}
		}
		else{
			for(int j=0;j<N;j++){
				if(b[i]==a[j]){
					printf("%d\n",j+1);
					break;
				}
			}
		}	
	}
}
