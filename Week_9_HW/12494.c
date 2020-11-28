// 
// 以數學模型來解釋的話，其實只是找最小的那個元素

#include <stdio.h>

int main(){
	int n, m, k;
	long long int tmp, min;
	scanf("%d %d", &n, &m);
	k = m*n;
	scanf("%lld", &min);
	k--;
	while(k--){
		scanf("%lld", &tmp);
		min = (tmp < min) ? tmp : min;
	}
	printf("%lld\n", min);

}