#include <stdio.h>

void swap(int* container, int a, int b) {
	int temp = 0;
	temp = container[a];
	container[a] = container[b];
	container[b] = temp;
}

int main() {
	int container[5] = {0, 1, 2, 3, 4};
	int num = 0, a, b;
	scanf("%d", &num);
	for (; num > 0; num--) {
		scanf("%d %d", &a, &b);
		swap(container, a, b);
	}
	for (int i = 0; i < 4; i++) {
		printf("%d ", container[i]);
	}
	printf("%d", container[4]);
}