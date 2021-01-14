// x = 2^i + k
// y = (2^i-1)k + k(k-1)/2
#include <iostream>

#define NUM 5000000000

using namespace std;

long long two_p[64];

void sol(long long y)
{
	long long tmp, l, r, mid, calc;

	for(int i = 0; i < 64; i++)
	{
		// Lucky -> k = 1
		if(two_p[i] == y+1)
		{
			cout << two_p[i] << "\n";
			return;
		}

		// Binary Search
		l = 0;
		r = NUM<y?NUM:y;
		while(l<r)
		{
			mid = (l+r)/2;
			calc = mid*2+1;
			tmp = (two_p[i]-1) + (calc-1)/2;
			if(tmp*calc >= y) r = mid;
			else l = mid+1;
		}
		calc = r*2+1;
		tmp = (two_p[i]-1) + (calc-1)/2;
		if(tmp*calc == y)
		{
			cout << two_p[i]*calc << "\n";
			return;
		}
	}
	cout << "-1" << "\n";
	return;
}

int main()
{
	int t;
	long long y;
	cin >> t;

	// create a arr for [1,2,4,8,16,32,....]
	two_p[0] = 1;
	for(int i = 1; i <= 64; i++)
		two_p[i] = two_p[i-1]*2;
	
	while(t--)
	{
		cin >> y;
		if(y >= 1) sol(y);
		else cout << "0" << "\n";
	}

	return 0;
}