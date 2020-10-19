#include <stdio.h>
#define ll unsigned long long
ll x, y, m, tmp;
ll result = 1;

//迴圈
/*
ll fast_power(ll x, ll y, ll m){
	if(y == 0) return 1 % m;
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
*/

//遞迴
ll fast_power(ll x, ll y, ll m){
	if(y == 0) return 1%m; //陷阱：要考慮 m == 1 的狀態
	else if(y%2 == 0){
		ll tmp = fast_power(x, y/2, m);
		return (tmp*tmp)%m;
	}
	else{
		ll tmp = fast_power(x, y/2, m);
		return (((tmp*tmp)%m)*x)%m;
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

/*
775477547754 775477547754 10235876
-> 9284380
*/


