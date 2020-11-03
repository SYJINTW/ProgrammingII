#include <stdio.h>
#include <stdlib.h>

#define NUM 1000000007

int matrix[3][3] = {{1, 2, 1}, {1, 0, 0}, {0, 1, 0}};
int tmp[3][3];
int var[3] = {1, 12, 13};
int t_var[3];

void matrix_mul(){
	int sum;
	//row
	for(int i = 0; i < 3; i++){
		//col
		for(int k = 0; k < 3; k++){
			sum = 0;
			for(int j = 0; j < 3; j++){
				sum = sum + (matrix[i][j]*matrix[j][k])%NUM;
			}
			tmp[i][k] = sum;
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			matrix[i][j] = tmp[i][j];
		}
	}
}

void matrix_var(){
	int sum;
	for(int i = 0; i < 3; i++){
		sum = 0;
		for(int j = 0; j < 3; j++){
			sum = sum + (matrix[i][j]*var[j])%NUM;
		}
		t_var[i] = sum;
	}
	for(int i = 0; i < 3; i++){
		var[i] = t_var[i];
	}
}

int main(){
	unsigned long long t, x;
	unsigned long long ans;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &x);
		if(x == 1){
			ans = 1;
		}
		else if(x == 2){
			ans = 12;
		}
		else if(x == 3){
			ans = 13;
		}
		else{
			while(x){
				if(x%2 == 0){
					matrix_mul();
					x = x/2;
				}
				else{
					matrix_var();
					x--;
				}
			}
			ans = var[0];
		}
		printf("%lld\n", ans);
	}
}	




