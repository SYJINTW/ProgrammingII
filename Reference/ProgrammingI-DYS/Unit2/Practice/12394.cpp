#include<stdio.h>
int main(int argc, char const *argv[])
{
	float i, temp = 0;
	int a, b;
	scanf("%f", &i);
	a = (int)i;
	b = (int)(i * 1000) % 1000;

	for (int x = 100; x > 0; x /= 10) {
		i += (a % 10) * x;
		a /= 10;
	}

	for (float x = 0.1; x > 0.0001; x /= 10) {
		i += (b % 10) * x;
		b /= 10;
	}
	printf("%.03f", i);
	return 0;
}