#include<stdio.h>

int main(void) {
	int x = 0, y = 0;
	float sum = 0;
	scanf("%d", &x);
	sum = x;
	for (; x ; x /= 10) {
		y *= 10;
		y += (x % 10);
	}
	sum += y;
	printf("%.1f", sum/2);

}