#include <stdio.h>
#include <stdlib.h>

long long int preorder_sum[1000002];//sum will too big, so need to use long long int
long long int sum, tmp;
int l, r, m;
int change_point; //設一個轉折點，直接在輸入的時候記下來，這樣就不用再確定一次

int main(){
	int n, q;
	scanf("%d %d", &n, &q);

	preorder_sum[0] = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &tmp);
		if(tmp >= 0){
			preorder_sum[i] = preorder_sum[i-1] + tmp;
			change_point = i; //record the change_point(positive to negative)
		}
		//if tmp is negative, means that the preorder sum will not be bigger
		else{
			preorder_sum[i] = -1; //don't calculate the negative sum, just simply it as -1
		}
	}

	while(q--){
		scanf("%d %d %d", &l, &r, &m);
		//incorrect loot number
		if(m > r-l+1){
			printf("0\n");
			continue;
		} else;

		//correct loot number
		//find if l+m-1 is behind change_point(the last positive number position)
		if(l+m-1 >= change_point){
			r = change_point;
		}
		else{
			r = l + m - 1;
		}

		//print the answer
		if(r >= l){
			printf("%lld\n", preorder_sum[r] - preorder_sum[l-1]);
		}
		else{
			printf("0\n");
		}
	}
}


