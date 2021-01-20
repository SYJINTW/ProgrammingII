#include<stdio.h>
int main(){
	int dir_x=-1,dir_y=1;
	int H,W,cur=0,iscorner=0,x,y,T;
	scanf("%d%d",&H,&W);
	scanf("%d%d",&x,&y);
	scanf("%d",&T);
	T-=1;
	if(H==W){
		T%=4;
	}
	for(int i=0;i<T&&iscorner==0;i++){
		do{
			x+=dir_x;
			y+=dir_y;
		}while(x!=1&&x!=H&&y!=1&&y!=W);
		if(x==1||x==H){
			dir_x=-dir_x;
		}
		else{
			dir_y=-dir_y;
		}
		if((x==H||x==1)&&(y==W||y==1)){
			iscorner=1;
		}
	}
	printf("(%d,%d)",x,y);
} 
