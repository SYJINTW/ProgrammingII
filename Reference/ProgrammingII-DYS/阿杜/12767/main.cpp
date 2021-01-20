// Author: justin0u0<dancinglinkxalgorithm@gmail.com>
#include <iostream>
#include "function.h"
using namespace std;

/*
 * HINT: To solve this problem
 * First, assuming there is an array containing the first F(N, 1) ~ F(N, N)
 * to compute F(N, N + 1), we can construct a matrix that multiply the array(N*1 matrix)
 * from F(N, 1) ~ F(N, N) to F(N, 2), F(N, N + 1),
 * so to compute F(N, N + 2), we can just multiply the array again.
 *
 * For example, if N = 2, then
 * [ 0, 1 ]   [ 1 ]   [ 1 ]       [ 0, 1 ]   [ 1 ]   [ 2 ]
 * [      ] * [   ] = [   ], then [      ] * [   ] = [   ], ....
 * [ 1, 1 ]   [ 1 ]   [ 2 ]       [ 1, 1 ]   [ 2 ]   [ 3 ]
 */

int main() {
  int n, m;
  cin >> n >> m;
  if (m <= n) {
    cout << 1 << endl;
  } else {
    Matrix base = constructMatrix(n);
    base = base.power(m - n);
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans = (ans + base(n - 1, i)) % mod;
    cout << ans << endl;
  }
  return 0;
}
