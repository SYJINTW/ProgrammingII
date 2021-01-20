#include<stdio.h>
int main(){
	int games[1000],bills[1000],m,n,game=0,bill=0;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++){
		scanf("%d",&games[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&bills[i]);
	}
	while(game!=m&&bill<n){
		if(bills[bill]>=games[game]){
			bill++;
			game++;
		}
		else{
			game++;
		}
	}
	printf("%d\n",bill);
}
