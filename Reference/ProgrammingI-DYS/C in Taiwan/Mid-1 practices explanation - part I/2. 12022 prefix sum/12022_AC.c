#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000005

long long prefix_sum[MAX_SIZE];

int main()
{
  int num;
  int N, M, QueryLeft, QueryRight;

  scanf("%d", &N);

  for (int i = 1; i <= N; i++)
  {
    scanf("%d", &num);
    prefix_sum[i] = num + prefix_sum[i - 1];
  }

  scanf("%d", &M);

  for (int i = 0; i < M; i++)
  {
	scanf("%d%d", &QueryLeft, &QueryRight);
	printf("%lld\n", prefix_sum[QueryRight] - prefix_sum[QueryLeft - 1]);
  }

  return 0;
}
