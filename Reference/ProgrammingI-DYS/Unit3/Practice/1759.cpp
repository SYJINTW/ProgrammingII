#include<stdio.h>
#include<math.h>

int main() {
	int a, k;
	long long int sum = 0, temp = 0;
	scanf("%d %d", &a, &k);

	temp = 1;
	for (int i = k; i > 0; i--) {
		sum += a * i * temp;
		temp *= 10;
	}

	//One Error
	/*
	for (int i = 1; i <= k; i++) {
		temp = 0;
		for (int j = 0; j < i; j++) {
			temp += a * pow(10, j);
		}
		sum += temp;
	}
	*/
	
	printf("%lld\n", sum);
	return 0;

}