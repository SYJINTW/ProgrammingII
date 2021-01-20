#include <iostream>
using namespace std;

#include "12722.h"

int main() {
  oj::Fib fib;

  int Q;
  cin >> Q;
  
  while (Q--) {
    int P, A, B;
    cin >> P;

    if (P == 0) {
      cin >> A >> B;
      fib.setBase(A, B);
    } else {
      cin >> A;
      cout << fib[A] << endl;
    }
  }

  return 0;
}
