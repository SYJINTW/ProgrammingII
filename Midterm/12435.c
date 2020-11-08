#include <stdio.h>
#include <stdlib.h>
#define ul long long int
#define NUM 1000000007

//define struct
typedef struct{
	ul time;
	ul value;
} arr_struct;

//define variables
ul n, q, tmp;
arr_struct arr[1000009]; //start from 1 to n


ul binarySearch(ul x){
	ul l = 1, r = n, mid;
	ul ans = 1; //ans is last time mid (for when the last time is found)
	while(l < r){
		mid = (r+l)/2;
		//find left
		if(arr[mid].value >= x){
			ans = mid;
			r = mid;
		}
		//find right
		else{
			l = mid+1;
			ans = l;
		}
	}
	//find the ans (l == r)
	if(arr[ans].value == x){
		return arr[ans].time;
	}
	//didn't find the ans (l < r)
	else{
		return 0;
	}
}

ul fpow(ul k){
	ul base = 2;
	ul ans = 1;
	while(k){
		/*
		if(k&1){
			ans = ((ans)%NUM * (base)%NUM) % NUM;
		}
		base = ((base)%NUM * (base)%NUM) % NUM;
		k = k >> 1;
		*/
		if(k % 2 == 0){
			base = ((base)%NUM * (base)%NUM) % NUM;
			k = k/2;
		}
		else{
			ans = ((ans)%NUM * (base)%NUM) % NUM;
			k--;
		}
	}
	return ans;
}


/*** 背起來 ***/
//for qsort() 
int cmp(const void * a, const void * b){
   return (*(arr_struct*)a).value - (*(arr_struct*)b).value;
}

int main(){
	while(scanf("%lld %lld", &n, &q) != EOF){
		for(int i = 0; i < 1000009; i++){
			arr[i].time = -1;
			arr[i].value = -1;
		}

		for(int i = 1; i <= n; i++){
			scanf("%lld(/`A`)/ ~I__I", &tmp);
			if(tmp % 2 == 0){
				arr[i].value = fpow(tmp/2);
				arr[i].time = i;
			}
			else{
				arr[i].value = 0;
				arr[i].time = i;
			}
		}

		qsort(arr+1, n, sizeof(arr_struct), cmp);

		while(q--){
			ul x, ans;
			scanf("%lld", &x);
			ans = binarySearch(x);
			if(ans == 0){
				printf("Go Down Chicken 404\n");
			}
			else{
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}