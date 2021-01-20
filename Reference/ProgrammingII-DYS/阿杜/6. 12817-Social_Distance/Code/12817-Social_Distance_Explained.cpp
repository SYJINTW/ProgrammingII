#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Seg {
  int left, right;
  Seg(int a, int b) : left(a), right(b) {}
};

struct Cmp {
  bool operator()(const Seg &lhs, const Seg &rhs) const {
    int l_len = (lhs.right - lhs.left) / 2;
    int r_len = (rhs.right - rhs.left) / 2;
    if (l_len != r_len)
      return l_len > r_len;
    else
      return lhs.left < rhs.left;
  }
};

int main() {
  char cmd;
  int n, m, s, x, D;
  set<int> pos;
  set<Seg, Cmp> seg;
  vector<int> id2pos;

  cin >> n >> m >> s;
  D = n + 1;
  id2pos.resize(m + 1, -1);
  pos.insert(0);
  pos.insert(n + 1);
  seg.insert(Seg(0, n + 1));

  for (int t = 0; t < 2 * m; t++) {
    cin >> cmd >> x;
    if (cmd == 'i') {
      auto it = seg.begin();
      int left = it->left, right = it->right;
      int mid = (left + right) / 2;
      if (left != 0)
        D = min(mid - left, D);
      if (right != n + 1)
        D = min(right - mid, D);
      seg.erase(it);
      seg.insert(Seg(left, mid));
      seg.insert(Seg(mid, right));
      id2pos[x] = mid;
      pos.insert(mid);
    } else if (cmd == 'o') {
      int mid = id2pos[x];
      auto it = pos.find(mid);
      auto left_it = it, right_it = it;
      int left = *(--left_it), right = *(++right_it);
      seg.erase(Seg(left, mid));
      seg.erase(Seg(mid, right));
      seg.insert(Seg(left, right));
      id2pos[x] = -1;
      pos.erase(mid);
    }
  }

  if (D >= s)
    cout << "YES\n";
  else
    cout << "NO\n";
  if (D == n + 1)
    cout << "INF\n";
  else
    cout << D << "\n";
    
  return 0;
}
