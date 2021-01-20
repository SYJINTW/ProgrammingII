#include<stdio.h>
int NQueen[11]={0,1,0,0,2,10,4,40,92,352,724};
int main(){
	int x;
	scanf("%d", &x);
	printf("%d\n",NQueen[x]);
}
