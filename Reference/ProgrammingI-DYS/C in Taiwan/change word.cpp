#include<stdio.h>
int main(){
	char a[6]={0};
	for(int i=0;i<5;i++){
		a[i]=getchar();
		a[i]='a'+'z'-a[i];
	}
	puts(a);
}
