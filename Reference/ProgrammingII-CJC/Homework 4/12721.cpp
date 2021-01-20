#include <iostream>
using namespace std;

#include "12721.h"

int main() {
  oj::BST bst;

  int Q;
  cin >> Q;

  while (Q--) {
    int P, V;
    cin >> P;

    if (P == 0) {
      cin >> V;
      bst.insert(V);
    } else if (P == 1) {
      cin >> V;
      bst.erase(V);
    } else {
      cout << bst.inorder() << endl;
    }
  }

  return 0;
}
