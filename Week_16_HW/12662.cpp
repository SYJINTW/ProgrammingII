#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, p, k, tmp;
	vector <int> price;
	vector <int> prefix_sum;
	cin >> t;
	while(t--)
	{
		cin >> n >> p >> k;
		price.push_back(0);
		for(int i = 1; i <= n; i++)
		{
			cin >> tmp;
			price.push_back(tmp);
		}

		sort(price.begin(), price.end());

		int i = 0;
		prefix_sum.push_back(0);
		for(i = 1; i < k; i++)
			prefix_sum.push_back(price[i]+prefix_sum[i-1]);
		for(; i <= n; i++)
			prefix_sum.push_back(price[i]+prefix_sum[i-k]);

		int pos;
		for(pos = n; pos > 0; pos--)
		{
			if(prefix_sum[pos] <= p) break;
			else;
		}
		cout << pos << endl;
		price.clear();
		prefix_sum.clear();
	}

}