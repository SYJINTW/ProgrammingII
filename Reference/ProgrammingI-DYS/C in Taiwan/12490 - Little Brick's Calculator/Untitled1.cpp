#include<stdio.h>
void hanoi(int n, char from, char to, char temp){
	if(n==1){
		printf("move %d from %c to %c\n",n,from,to);
		return ;
	}
	else{
		hanoi(n-1, from,temp,to);
		printf("move %d from %c to %c\n",n,from,to);
		hanoi(n-1,temp,to,from);
	}
}
int main(){
	int x;
	char a='a',b='b',c='c';
	scanf("%d",&x);
	hanoi(x,a,c,b);
} 
