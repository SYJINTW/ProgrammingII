#include<stdio.h>
int main(){
	int x,LB,RB,T;
	scanf("%d",&x);
	double a[x+1];
	a[0]=0;
	for(int i=1;i<=x;i++){
		scanf("%lf",&a[i]);
		a[i]+=a[i-1]; 
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&LB,&RB);
		printf("%.0f\n",a[RB]-a[LB-1]);
	}
}
