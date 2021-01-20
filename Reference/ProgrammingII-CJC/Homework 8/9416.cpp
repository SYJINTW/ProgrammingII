#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num;
    while( cin >> num ) {
        if(num == 0) {
            break;
        }
        vector<string> vec;
        while(num--) {
            string str;
            cin >> str;
            vec.push_back(str);
        }
        sort(vec.begin(), vec.end());
        for(auto element : vec) {
            cout << element << endl;
        }
        cout << endl;
    }
    return 0;
}