#include <stdio.h>

#define ll unsigned long long
ll a, b, i, a_tmp, b_tmp;
ll f1, f2, f3, f4, tmp; //matrix
ll k = 1000000007; //mod

int main(){
	//Matrix Way
	while(scanf("%llu", &i) != EOF){
		//init (a,b)
		a = 1;
		b = 1;
		//init the matrix
		f1 = 1;
		f2 = 1;
		f3 = 1;
		f4 = 0;
		//start from i = 3
		if(i > 2){
			//i = 3 only have to add the matrix once
			i -= 2;
			while(i){
				if(i % 2 == 1){
					//Add one matrix into (a,b)
					a_tmp = a;
					b_tmp = b;
					a = (((f1*a_tmp)%k)+((f2*b_tmp)%k))%k;
					b = (((f3*a_tmp)%k)+((f4*b_tmp)%k))%k;
					i--;
				}
				else{
					//Combine two matrix into one
					tmp = f2;
					f2 = ((f1+f4)*tmp)%k;
					f3 = f2;
					f1 = (tmp*tmp + f1*f1)%k;
					f4 = (tmp*tmp + f4*f4)%k;
					i /= 2;
				}
			}
		} else;
		printf("%llu\n", a);
	}

//Basic Way
/*
	while(scanf("%lld", &i) != EOF){
		a = 1;
		b = 1;
		while(i > 2){
			tmp = a;
			a = (a+b)%k;
			b = tmp;
			i--;
		}
		printf("%lld\n", a);
	}
*/
	return 0;
}
