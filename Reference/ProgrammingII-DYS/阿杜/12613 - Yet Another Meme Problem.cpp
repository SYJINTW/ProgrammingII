#include<stdio.h>
#include<math.h>
int main(){
	long long int A,B,pairs,T,op;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&A,&B);
		op=0;
		while(B/=10){
			op++;
		}
		printf("%lld\n",op*A);
	}
}
