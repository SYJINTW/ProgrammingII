// cin cout 比 scanf printf 慢太多了
#include <stdio.h>
#define NUM 1000001

int main()
{
	int n, a, b, num, ct;
	int sum[NUM];
	scanf("%d", &n);
	for(int i = 1; i <= NUM; i++)
	{
		num = i;
		ct = 0;
		while(num)
		{
			if(num%10==1) ct++;
			num/=10;
		}
		sum[i] = sum[i-1] + ct;
	}

	while(n--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a-1]);
	}
	return 0;
}