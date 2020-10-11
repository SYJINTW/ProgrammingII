#include<stdio.h>
#include<string.h>

long int i;
long long int k, l, r;
char arr[100000000000] = {'\0'};

void sprint(long long int n){
	if(n == 1){
		arr[i++] = 'O';
		arr[i++] = 'u';
		arr[i++] = 'Q';
	}
	else{
		arr[i++] = 'O';
		sprint(n-1);
		arr[i++] = 'u';
		sprint(n-1);
		arr[i++] = 'Q';
	}
}


int main(){
	while(~scanf("%lld%lld%lld", &k, &l, &r)){
		i = 0;
		//solve
		sprint(k);
		//make l < r
		if(l > r){
			long long int temp = l;
			l = r;
			r = l;
		} else;
		//print
		for(long long int j = l; j <= r; j++){
			printf("%c", arr[j]);
		}
		printf("\n");
	}
	return 0;
}
