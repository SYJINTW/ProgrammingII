#include <stdio.h>
#define ll unsigned long long
ll x, y, m, tmp;
ll result = 1;

ll fast_power(ll x, ll y, ll m){
	if(y == 0) return 1;
	else{
		result = 1;
		while(y != 1 && x != 0){
			if(y % 2 == 0){
				x = (x * x) % m;
				y = y/2;
			}
			else{
				result = (result * x)%m;
				y--;
			}
		}
		result = (result * x)%m;
		return result;
	}
}


int main(){
	scanf("%llu %llu %llu", &x, &y ,&m);
	if(m == 0){
		printf("0\n");
	}
	else{
		x %= m;
		printf("%llu\n", fast_power(x, y, m));
	}
}
//
//775477547754 775477547754 10235876
