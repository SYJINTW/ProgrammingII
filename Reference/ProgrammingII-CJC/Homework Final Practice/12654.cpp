#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int N;
    cin >> N;
    vector<int> left;
    vector<int> right;

    for (int i=0; i<N; ++i) {
        int l, r;
        cin >> l >> r;
        left.push_back(l);
        right.push_back(r);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int max_overlap = 0, cur_overlap = 0;

    int i=0, j=0;
    while(i < left.size() && j < right.size()) {
        if(left[i] < right[j]) {
            cur_overlap++;
            max_overlap = max(max_overlap, cur_overlap);
            i++;
        } else {
            cur_overlap--;
            j++;
        }
    }

    cout << max_overlap << endl;
    return 0;
}