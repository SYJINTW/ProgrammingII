#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// G[i] is the neighbor towns of town i
vector<int> diamondTowns;
vector<int> G[100005];
int Dist[100005];

struct node {
    int id;
    int dist;
    node(int id, int l) {
        this->id = id;
        this->dist = l;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        diamondTowns.push_back(x);
    }
    fill(Dist, Dist+100005, -1);

    queue<node> Q;

    for(int i=0;i<K;i++){
        Q.push(node(diamondTowns[i],0));
    }
    while(!Q.empty()){
        node tmp = Q.front();
        Q.pop();
        if(Dist[tmp.id]==-1){
            Dist[tmp.id] = tmp.dist;
            for(auto c:G[tmp.id]){
                Q.push(node(c,tmp.dist+1));
            }
        }
    }

    // [TODO] complete the task!

    // Output
    for (int i = 1; i <= N; i++) {
        cout << Dist[i] << '\n';
    }
    return 0;
}
