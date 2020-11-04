#include <stdio.h>
#include <stdlib.h>

#define NUM 1000000007

unsigned long long matrix[3][3];
unsigned long long t_matrix[3][3];
unsigned long long var[3];
unsigned long long t_var[3];

void matrix_mul(){
	//initial t_matrix
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			t_matrix[i][j] = 0;
		}
	}
	//calculate
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				t_matrix[i][j] = (t_matrix[i][j] + (matrix[i][k] * matrix[k][j])%NUM)%NUM;
			}
		}
	}
	//record
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			matrix[i][j] = t_matrix[i][j];
		}
	}
}

void matrix_var(){
	//initial t_var
	for(int i = 0; i < 3; i++){
		t_var[i] = 0;
	}
	//calculate
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			t_var[i] = (t_var[i] + (matrix[i][j] * var[j])%NUM)%NUM;
		}
	}
	//record
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
		//initial
		matrix[1][1] = matrix[1][2] = matrix[2][0] = matrix[2][2] = 0;
		matrix[0][0] = matrix[0][2] = matrix[1][0] = matrix[2][1] = 1;
		matrix[0][1] = 2;
		var[0] = 13; var[1] = 12; var[2] = 1;

		if(x == 1) ans = var[2];
		else if(x == 2) ans = var[1];
		else if(x == 3) ans = var[0];
		else{
			x = x - 3;
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
	
	/*
	matrix_mul();
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%lld ", matrix[i][j]);
		}
		printf("\n");
	}
	matrix_mul();
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%lld ", matrix[i][j]);
		}
		printf("\n");
	}
	*/

	return 0;
}	




