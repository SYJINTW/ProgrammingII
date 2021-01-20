#include <stdio.h>

#define maxn 10000010

const int INF = 0x3f3f3f3f;

int a[maxn];
int box[maxn];
int ans[maxn];

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	a[0] = INF;
	
	int top = 0;
	box[top] = 0;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		while (a[box[top]] < a[i])
			top--;
		if (i - box[top] - 1 == x)
			ans[idx++] = i;
		box[++top] = i;
	}
	if (idx > 0) {
		printf("%d", ans[0]);
		for (int i = 1; i < idx; i++)
			printf(" %d", ans[i]);
		printf("\n");
	} else {
		printf("ouo\n");
	}
	return 0;
}
