#include<stdio.h>
int main(){
	int a[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int idx=0,idy=0,sec,idd=0,ask=0,stepsn,stepso=0;
	while(ask!=2){
		idd=(idd+4)%4;
		scanf("%d%d",&stepsn,&ask);
		sec=stepsn-stepso;
		while(sec--){
			idx+=a[idd][0];
			idy+=a[idd][1];
		}
		if(ask==1){
			idd--;
		}
		else 
			idd++;
		stepso=stepsn;
	}
	printf("%d %d\n",idx*10,idy*10);
}
