#include <iostream>
#include <iomanip>
#include <math.h>
#include <set>

#define ll long long int
#define NUM 5000000000

using namespace std;

int t;
ll n;

ll BS(ll i)
{
	ll r, l, mid, calc;
	// Find k
	l = 0;
	r = NUM;
	while(l < r)
	{
		mid = (l+r)/2;
		calc = mid*2+1;
		if(calc*i+calc*(calc-1)/2 > n) r = mid-1;
		if(calc*i+calc*(calc-1)/2 < n) l = mid+1;
		if(calc*i+calc*(calc-1)/2 == n) return calc;
	}
	return -1;
}

int main()
{
	ll ans;
	set <ll> myset; 
	cin >> t;
	while(t--)
	{
		cin >> n;

		// y = (2i-1)k + k(k-1)/2
		// Assume i
		for(int i = 0; i < 64; i++)
		{
			// Find k
			ans = BS(pow(2,i)-1);
			if(ans != -1)
			{
				cout << "i: " << i << endl;
				cout << "calc: " << ans << endl;
				cout << "ans: " << pow(2,i)*ans << endl;
				myset.insert(pow(2,i)*ans);
			}
			else;
		}

		if(!myset.empty()) cout << *myset.begin() << endl;
		else cout << -1 << endl;
		myset.clear();
	}

}