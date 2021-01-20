#include<stdio.h>
int isy(int year){
	if(year%4==0&&year%100!=0||year%400==0)
		return 2;
	else
		return 1;
}
int main(){
	int T,y,reminder,x;
	scanf("%d",&T);
	while(T--){
		reminder=0;
		scanf("%d",&y);
		x=y;
		do{
			reminder+=isy(y);
			y++;
			
		}while(reminder%7!=0||isy(x)!=isy(y));
		printf("%d\n",y);
	}
}
