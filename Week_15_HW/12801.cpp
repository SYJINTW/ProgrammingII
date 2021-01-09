#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long int> myvec;
int t;
long long int n, m;

long long int Codes(long long int day)
{
	long long int effect = 0, result = 0, count = 0;
	for(long long int i = 0; i < n; i++)
	{
		if(myvec[i] - effect > 0) result += myvec[i] - effect;
		else result += 0;

		if(++count >= day)
		{
			count = 0;
			effect++;
		}
		else;
	}

	//cout << "result: "<< result << endl;
	return result;
}

int main()
{
	long long int l, r, mid, ans, tmp;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 0; i < n; i++)
		{
			cin >> tmp;
			myvec.push_back(tmp);
		}
		sort(myvec.begin(), myvec.end(), greater<int>());
		
		ans = -1;
		l = 1;
		r = n+1;
		
		while(l < r)
		{
			mid = (l+r)/2;
			if(Codes(mid) >= m)
			{
				ans = mid;
				r = mid;
			}
			else l = mid+1;
			//cout << "ans: "<< ans << endl;
		}

		cout << ans << "\n";

		myvec.clear();
	}
}

/*
	//print vector
	for(auto x : myvec)
	cout << x << " ";
	cout << '\n';
*/


