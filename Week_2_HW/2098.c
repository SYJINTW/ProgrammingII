//Use Pointer to solve IEEE-754
#include<stdio.h>

float x;

int main(){
	long long int ans;
	long long int tmp;
	
	while(scanf("%f", &x) != EOF){
		
		unsigned int* y = (unsigned int*)(&x); //important 
		
		ans = 0;

		//dec into bin
		for(int i = 31; i >= 0; i--){
			tmp = *y >> i;
			if(tmp & 1)printf("1");
			else printf("0");	
		}

		printf("\n");
	}
}

