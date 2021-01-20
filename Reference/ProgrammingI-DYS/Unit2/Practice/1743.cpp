#include<stdio.h>

int first4(int x) {
	return x / 10000;
}
int last4(int x) {
	return x % 10000;
}
int first8(int x) {
	return x / 100000000;
}
int last8(int x) {
	return x % 100000000;
}

int main() {
	int insert = 0, a = 0, b = 0;
	int c1 = 0, c2 = 0, c3 = 0;
	scanf("%d", &insert);
	a = first4(insert);
	b = last4(insert);
	c3 = last4(b * b);
	c2 = first4(b * b) + last4(a * a) * 10000 + a * b * 2;
	c1 = first4(a * a);
	printf("%4d%08d%04d", c1, c2, c3);
	return 0;
}