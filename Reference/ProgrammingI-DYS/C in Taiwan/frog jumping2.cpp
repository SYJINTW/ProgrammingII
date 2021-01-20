#include<stdio.h>
#include<math.h>
int a[27],cost[27],step[27];
int main(){
	int stone,t1,t2;
	scanf("%d",&stone);
	for(int i=1;i<=stone;i++)scanf("%d",a+i);
	cost[2]=fabs(a[2]-a[1]);
	step[2]=1;
	for(int i=3;i<=stone;i++){
		t1=cost[i-1]+fabs(a[i]-a[i-1]);
		t2=cost[i-2]+fabs(a[i]-a[i-2]);
		if(t1<t2){
			cost[i]=t1;
			step[i]=step[i-1]+1;
		}
		else if(t1>t2){
			cost[i]=t2;
			step[i]=step[i-2]+1;
		}
		else{
			cost[i]=t1;
			step[i]=(step[i-1]<step[i-2])?step[i-1]+1:step[i-2]+1;
		}
	}
	printf("%d %d\n",cost[stone],step[stone]);
}
