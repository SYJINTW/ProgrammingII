#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool grouped[10005];
int t; // t rounds
int n, r, k; // n lines, r range, k size


bool connect(int x1, int y1, int x2, int y2)
{
	if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) <= r*r) return true;
	else return false;
}

int dfs(int now, vector <tuple<int, int>> nodes)
{
	int sum = 1;
	grouped[now] = true;
	for(int i = 0; i < n; i++)
	{
		if(grouped[i] != false) continue;
		else if(i == now) continue;
		else if(connect(get<0>(nodes[now]), get<1>(nodes[now]), get<0>(nodes[i]), get<1>(nodes[i])))
		{
			sum = sum + dfs(i, nodes);
		} else;
	}
	return sum;
}

int main()
{
	cin >> t;
	while(t--)
	{
		int greater = 0, less = 0;
		vector<tuple<int, int>> nodes;
		cin >> n >> r >> k;
		// input the (x,y) of nodes
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			nodes.push_back({x, y});
			grouped[i] = false;
		}
		//dfs
		for(int i = 0; i < n; i++)
		{
			if(grouped[i] == 1) continue;
			else if(dfs(i, nodes) >= k) greater++;
			else less++;
		}
		cout << less << " " <<  greater << endl;
		
		nodes.clear();
	}
	
	return 0;
}