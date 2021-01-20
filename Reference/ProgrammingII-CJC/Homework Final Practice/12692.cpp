#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[200001];
int val_root;

void DFS(int id, int level, int pre) {
    val_root += level;
    for (auto ele : edge[id]) {
        if(ele != pre)
            DFS(ele, level+1, id);
    }
}

int main() {
    int N, S;
    cin >> N >> S;
    for (int i=0; i<N-1; ++i) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    DFS(S, 0, 0);
    cout << val_root << endl;
    return 0;
}