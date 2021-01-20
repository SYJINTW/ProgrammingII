#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    multiset<int, greater<int>> container;

    string cmd;
    while(cin >> cmd) {
        if(cmd == "PUSH") {
            int num;
            cin >> num;
            container.insert(num);
        } else if (cmd == "POPMIN") {
            if(container.empty())
                continue;
            container.erase(--container.end());
        } else if (cmd == "POPMAX") {
            if(container.empty())
                continue;
            container.erase(container.begin());
        } else if (cmd == "MIN") {
            if(container.empty()){
                cout << "Null\n";
                continue;
            }
            cout << *(--container.end()) << endl;
        } else if (cmd == "MAX") {
            if(container.empty()){
                cout << "Null\n";
                continue;
            }
            cout << *(container.begin()) << endl;
        } else if (cmd == "CLEAR") {
            container.clear();
        }
    }
    return 0;
}