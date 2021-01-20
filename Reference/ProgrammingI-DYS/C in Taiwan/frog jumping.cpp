#include<stdio.h>
#include<math.h>
#define N 27
int b[N];
int mineng(int stone);
int minstep(int stone);
int main(){
	int stone;
	scanf("%d",&stone);
	for(int i=1;i<=stone;i++){
		scanf("%d",&b[i]);
	}
	for(int i=stone;i>=1;i--){
		b[i]-=b[i-1];
	}
	printf("%d %d\n",mineng(stone),minstep(stone));
}
int mineng(int stone){
	int one,two;
	if(stone==1){
		return 0;
	}
	else if(stone==2){
		return fabs(b[stone]);
	}
	else{
		one = fabs(b[stone]) + mineng(stone-1);
		two = fabs(b[stone] + b[stone-1]) + mineng(stone-2);
		return (one<two)?one:two;
	}
}
int minstep(int stone){
	int one = 0,two = 0;
	if(stone==1){
		return 0;
	}
	else if(stone==2){
		return 1;
	}
	else if(b[stone]==0){
		one = minstep(stone-1);
		two = minstep(stone-2);
		return (one<two)?one+1:two+1;
	}
	if(mineng(stone)==(mineng(stone-1)+fabs(b[stone]))){
		one = minstep(stone-1);
	}
	if(mineng(stone)==(mineng(stone-2)+fabs(b[stone]+b[stone-1]))){
		two = minstep(stone-2);
	}
	if(two&&one)
		return (one<two)?one+1:two+1;
	else if(one)
		return one+1;
	else
		return two+1;
}
