#include <iostream>
#include <iomanip>
#include <vector>
#define MAX_SIZE 1005
using namespace std;

int n, r; // n:number of points, r:range
int X[MAX_SIZE]; // x value
int Y[MAX_SIZE]; // y value
bool G[MAX_SIZE]; // grouped or not

// calculate if the range from now to target is smaller than r
bool connect(int now, int target){
	int x = X[now] - X[target];
	int y = Y[now] - Y[target];
	if((x*x)+(y*y) <= r*r) return true;
	else return false;
}

//DFS
int dfs(int now){
	int sum = 1;
	G[now] = true;
	for(int i = 0; i < n; i++){
		if(G[i] == true) continue; // 已經被分組 (skip)
		else if(i == now) continue; // 自己本身 (skip)
		// 如果在 connect 的範圍內
		else if(connect(now, i)){
			sum = sum + dfs(i); // 計算經過多少個 point (先前的加上自己)
		} else;
	}
	return sum; // return how many points are in this group
}


int main(){
	int A = 0; // A: only one point in the group
	int B = 0; // B: more than one point in the group
	cin >> n >> r;

	// save (x, y) in X[] and Y[]
	for(int i = 0; i < n; i++){
		cin >> X[i] >> Y[i];
	}

	for(int i = 0; i < n; i++){
		if(G[i] == true) continue;
		else if(dfs(i) == 1) A++;
		else B++;
	}
	cout << A << " " << B << endl;
}
