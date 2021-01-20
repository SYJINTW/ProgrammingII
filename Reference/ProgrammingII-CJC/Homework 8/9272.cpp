#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> vec;
    make_heap(vec.begin(), vec.end());

    string command;
    while(cin >> command) {
        if(command == "PUSH") {
            int num;
            cin >> num;
            vec.push_back(num);
            push_heap(vec.begin(), vec.end());
        } else if (command == "POP") {
            pop_heap(vec.begin(), vec.end()); 
            vec.pop_back(); 
        } else if (command == "TOP") {
            if(vec.empty()){
                cout << "Null" << endl;
            } else {
                cout << vec.front() << endl;
            }
        } else {
            // do nothing
        }
    }

    return 0;
}