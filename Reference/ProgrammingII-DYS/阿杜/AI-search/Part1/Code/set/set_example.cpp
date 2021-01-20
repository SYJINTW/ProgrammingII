#include <iostream>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;  // otherwise we need to write std::set

int main()
{
    set<int> S{1, 2, 3, 4};

    // insert a new element into a set
    S.insert(5);
    for (auto c : S)
        cout << c << ' ';
    cout << '\n';

    // insert an existing element into a set
    S.insert(1);
    for (auto c : S)
        cout << c << ' ';
    cout << '\n';

    // We use the following idiom to find an element in a set.
    auto x = S.find(3); // x is an iterator
    if (x != S.cend()) {
        cout << "Found: " << *x << '\n';
    }

    // Generate all permutations and store them in a set.
    vector<int> v{1,2,3};
    set<vector<int>> T;
    do {
        T.insert(v);
    } while ( next_permutation(v.begin(), v.end()) );

    for (auto c : T)
        cout << c[0] << ' ' << c[1] << ' ' << c[2] << '\n';
    cout << '\n';

    // using bitset to generate power sets
    vector<string> vs{"RED","GREEN","BLUE"};
    for (int i=0; i<8; ++i) {
        bitset<3> b(i);
        for (int j=0; j<3; ++j) {
            if (b[j]==1) {
                cout << vs[j] << ' ';
            }
        }
        cout << '\n';
    }


}
