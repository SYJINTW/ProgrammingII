#include <iostream>
#include <vector>

using namespace std;
const int N = 200005;
vector<int> v[N];
long long sz[N], val[N], ans;
void DFS(int now, int d, int pre) {
	for(auto i : v[now]) {
		if(i == pre) continue;
		DFS(i, d + 1, now);
	}
	for(auto i : v[now]) {
		if(i == pre) continue;
		val[now] += val[i];
		sz[now] += sz[i];
	}
	sz[now]++;
	val[now] += sz[now];
	for(auto i : v[now]) {
		if(i == pre) continue;
		ans += (sz[now] - sz[i]) * (val[i]);
	}
}
int main() {
	int n; cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	DFS(1, 0, 0);
	cout << ans * 2 << endl;
	return 0;
}