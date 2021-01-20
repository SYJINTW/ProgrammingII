#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> q;

    string command;
    while(cin >> command) {
        if(command == "Push") {
            string name;
            cin >> name;
            q.push(name);
        } else if (command == "Front") {
            if(!q.empty()) {
                cout << q.front() << endl;
            } else {
                cout << "empty\n";
            }
        } else if (command == "Pop") {
            if(!q.empty())
                q.pop();
        }
    }
    return 0;
}