#include <iostream>
#include <cstdlib>
using namespace std;

#include "12728.h"

int main()
{
    // ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        oj::set bag;

        int N;
        cin >> N;

        while (N--)
        {
            int v;
            cin >> v;

            if (!bag.empty())
            {
                oj::iterator it = bag.lower_bound(v);
                if (it != bag.end()) {
                    cout << *it << "\n";
                }
            }
            bag.insert(v);
        }

        if (rand() & 1){
            bag.clear();
        }
    }

    return 0;
}
