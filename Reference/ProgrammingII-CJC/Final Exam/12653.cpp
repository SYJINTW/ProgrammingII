#include <iostream>
#include <vector>

using namespace std;

vector<int> edges[200005];
long long val[200005];
int children_size[200005];
int N;

void DFS1(int id, int level, int pre);
void DFS2(int id, int pre);

int main () {
    cin >> N;
    for (int i=0; i<N-1; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    DFS1(1, 0, -1);
    DFS2(1, -1);

    long long num = 0;
    for (int i=1; i<=N; ++i) {
        // cout << "val[" << i << "] = " << val[i] << endl;
        num += val[i];
    }
    cout << num << endl;

    return 0;
}

void DFS1(int id, int level, int pre) {
    for (int i=0; i<edges[id].size(); ++i) {
        if(edges[id][i] != pre) {
            DFS1(edges[id][i], level+1, id);
        }
    }

    val[1] += level;
    
    for(int i=0; i<edges[id].size(); ++i) {
        if(edges[id][i] != pre){
            children_size[id] += children_size[edges[id][i]];
            children_size[id]++;
        }
    }
}

void DFS2(int id, int pre) {
    if(id != 1) {
        val[id] = val[pre] + (N - children_size[id] - 2) - children_size[id];
    }

    for (int i=0; i<edges[id].size(); ++i) {
        if(edges[id][i] != pre) {
            DFS2(edges[id][i], id);
        }
    }
}