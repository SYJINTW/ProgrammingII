#include <iostream>
#include <set>

using namespace std;

struct Node {
    int ID;
    bool hasChild;

    Node(int id) : ID(id), hasChild(false) {}
};

struct compare {
    bool operator() (const Node &lhs, const Node &rhs) const{
        return lhs.ID > rhs.ID;
    }
};

int main() {
    int N;
    while(cin >> N) {
        if(N == 0) break;
        set<Node, compare> tree;
        while(N--) {

            int a, b;
            cin >> a >> b;

            Node aNode = Node(a);
            Node bNode = Node(b);
            auto it = tree.find(aNode);
            if(it == tree.end()) {
                aNode.hasChild = true;
                tree.insert(aNode);
            } else {
                tree.erase(aNode);
                aNode.hasChild = true;
                tree.insert(aNode);
            }
            tree.insert(bNode);
        }
        int R;
        cin >> R;
        int ans = 0;
        for(auto it = tree.begin(); it != tree.end(); ++it) {
            if(!(*it).hasChild) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}