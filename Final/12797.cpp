#include <iostream>
#include <iomanip>
#define NUM 100005

using namespace std;

int main()
{
	long long n, A, B, C, D, ans;
	long long arr[NUM];
	cin >> n;
	while(n--)
	{
		cin >> A >> B >> C >> D;
		ans = 0;
		for(long long i = 0; i < NUM; i++)
			arr[i] = 0;

		for(long long i = A; i <= B; i++)
		{
			arr[B+i] += 1;
			arr[C+i+1] += -1;
		}

		// prefix sum
		for(long long i = 1; i < NUM; i++)
			arr[i] += arr[i-1];

		// 有可能的 i 會是 [C, min(B+C,D)]
		for(long long i = C; i <= B+C; i++)
			ans += arr[i]*(min(i-1, D) - C + 1);

		cout << ans << endl;
	}
}