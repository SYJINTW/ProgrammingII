#include<stdio.h>
#include<string.h>
int main(){
	int M,N,T,a[1010][2];
	char str[1010][1010],c,d;
	scanf("%d%d%d",&M,&N,&T);
	for(int i=0;i<M;i++){
		for(int j=0;j<2*N;j++){
			c=getchar();
			if((c!='\n')&&(c!=' ')){
				str[i][(j-1)/2]=c;
			}
		}
	}
	for(int j=T-1;j>=0;j--){
		scanf("%d %d",&a[j][0],&a[j][1]);
	}
	for(int k=0;k<T;k++){
		for(int l=0;l<M;l++){
			c=str[l][a[k][0]-1];
			str[l][a[k][0]-1]=str[l][a[k][1]-1];
			str[l][a[k][1]-1]=c;
		}
	}
	for(int i=0;i<M;i++){
		printf("%s",str[i]);
	}
	printf("\n");
}
