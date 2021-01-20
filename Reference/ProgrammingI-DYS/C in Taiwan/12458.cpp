#include<stdio.h>
char str[1010];
int delete_map[1010][1010];
double find_parlidrome(int l, int r);
int main(){
	for(int i=0;i<1010;i++){
		for(int j=0;j<1010;j++){
			delete_map[i][j]=-1;
		}
	}
	double ans;
	int length, number;
	scanf("%d%d",&length, &number);
	scanf("%s", str);
	ans = find_parlidrome(0, length-1);
	if(ans <= number)
		printf("Yes\n");
	else
		printf("No\n");
}
double find_parlidrome(int l, int r){
	double left, right;
	if(l>=r){
		delete_map[l][r] = 0;
		return 0;
	}
	if(str[l]==str[r]){
		delete_map[l][r] = find_parlidrome(l+1, r-1);
		return delete_map[l][r]; 
	}
	else{
		if(delete_map[l][r]==-1){
			left = find_parlidrome(l+1, r) + 1;
			right = find_parlidrome(l, r-1) + 1;
			delete_map[l][r] = (left<right)?left:right;
			return delete_map[l][r];
		}
		else
		return delete_map[l][r];
	}
}
