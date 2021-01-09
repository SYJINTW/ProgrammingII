#include <iostream>
#include <iomanip>
#include <vector>
#include <set> 
#include <algorithm>
#define MAX 1000000000
using namespace std;


int main()
{
	int t, n, m, k;
	long long tmp;
	vector<long long> myvec;
	cin >> t;
	while(t--)
	{
		long long at_least = MAX, ans = 0;
		cin >> n >> m >> k;
		k = (k>m)?m-1:k;
		for(int i = 0; i < n; i++)
		{
			cin >> tmp;
			myvec.push_back(tmp);
		}

		for(int i = 0; i < k+1; i++)
		{
			at_least = MAX;
			for(int j = 0; j < m-k; j++)
			{
				//cout << "at least = " << at_least << " , " << "(" << myvec[i+j] << "," << myvec[i+j+(n-m)] << ")" << endl;
				at_least = min(at_least, max(myvec[i+j], myvec[i+j+(n-m)]));
			}
			//cout << "ans = " << ans << " , " <<  at_least << endl;
			ans = max(ans, at_least);
		}
		
		cout << ans << endl;
		myvec.clear();
	}
}