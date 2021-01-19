#include <iostream>
#include <algorithm>
using namespace std;

long long y;
int i;

long long bs(long long lower_bound, long long upper_bound) // k's bound
{

    long long test;
    long long k;
    long long _2powi;
    long long x = -1;

    while (lower_bound <= upper_bound)
    {
        _2powi = 1;

        k = (lower_bound + upper_bound) / 2;
        if (k % 2 == 0) {
            if (lower_bound != upper_bound)
                k++;
            else
                return x;
        }

        for (int j = 0; j < i; j++)
            _2powi *= 2;
        test = k * (_2powi - 1) + k * (k - 1) / 2;

        if (test < y)
            lower_bound = k + 1;
        else if (test > y)
            upper_bound = k - 1;
        else {
            x = _2powi * k;
            upper_bound = k - 1;
        }
    }
    return x;

}

int main(void)
{
    int t;
    long long x, ans;

    cin >> t;
    while (t--) {
        x = INT64_MAX;
        cin >> y;
        long long bound = 1;
        for (i = 62; i >= 0; i--) {
            ans = bs(1, bound);
            if (ans != -1 && ans < x)
                x = ans;
            if (bound * 2 < 5e9)
                bound = bound << 1;
        }
        if (x == INT64_MAX)
            cout << -1 << endl;
        else
            cout << x << endl;
    }

    return 0;
}