#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t, n, q, l, r;
	int max, ans, tmp, section;
	vector <pair<int, int>> soldier;
	int soldier_num[5001];
	cin >> t;
	while(t--)
	{
		//init
		max = 0;
		ans = 0;
		tmp = 0;
		section = 0;
		for(int i = 0; i < 5001; i++)
			soldier_num[i] = 0;

		cin >> n >> q;
 
		// input soldier
		soldier.push_back({0,0});
		for(int i = 1; i <= q; i++)
		{
			cin >> l >> r;
			soldier.push_back({l,r});
			for(int j = l; j <= r; j++)
				soldier_num[j]++;
		}

		// 刪掉第一層士兵（暴力）
		for(int i = 1; i <= q; i++)
		{
			int prefix_sum[5001] = {0};
			section = 0;
			for(int j = 1; j <= n; j++)
			{
				int num = soldier_num[j];
				if(j >= soldier[i].first && j <= soldier[i].second) num--;
				if(num > 0) section++;
				if(num == 1) prefix_sum[j] = prefix_sum[j-1] + 1;
				else prefix_sum[j] = prefix_sum[j-1];
			}
			//cout << "section: " << section << endl;

			// 刪掉第二層士兵
			for(int j = 1; j <= q; j++)
			{
				if(j == i) continue; // 略過第一層的
				tmp = prefix_sum[soldier[j].second] - prefix_sum[soldier[j].first-1];
				max = (section-tmp > max)?(section - tmp):max;
			}
			ans = (max>ans)?max:ans;
		}
		cout << ans << endl;
		soldier.clear();
	}

}