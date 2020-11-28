#include <stdio.h>
#include <stdlib.h>

unsigned long long A[100005];
int n = 0;
unsigned long long tmp = 0;

// for qsort
int cmp(const void *a, const void *b){
	return *(unsigned long long *)a - *(unsigned long long *)b;
}

// use binary search to find upper_bound and lower_bound
// 找到剛好比 target 大的值
int upper_bound(unsigned long long target){
	int l = 1;
	int r = n+1; // 重要：r 要設定成陣列後的一個
	int mid;
	while(l<r){
		mid = (l+r)/2;
		if(A[mid] <= target){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	return r;
}

// 找到剛好 target 的值
int lower_bound(unsigned long long target){
	int l = 1;
	int r = n+1; // 重要：r 要設定成陣列後的一個
	int mid;
	while(l<r){
		mid = (l+r)/2;
		if(A[mid] < target){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	return r;
}

int main(){
	unsigned long long target = 0;
	int q = 0;
	int upper, lower;
	scanf("%d",  &n);
	for(int i = 1; i <= n; i++){
		scanf("%llu", &A[i]);
	}
	qsort(A+1, n, sizeof(unsigned long long), cmp);

	// for debug
	/*
	for(int i = 1; i <= n; i++){
		printf("%llu ", A[i]);
	}
	*/

	scanf("%d", &q);
	while(q--){
		scanf("%llu", &target);
		upper = upper_bound(target);
		lower = lower_bound(target);
		//printf("lower: %d\n", lower);
		//printf("upper: %d\n", upper);
		printf("%d\n", upper - lower);
	}
}

// Input
/*
10
8 3 6 1 7 7 3 7 10 7
5
3
7
999
1
5
*/

// Output
/*
２
４
０
１
０
*/
