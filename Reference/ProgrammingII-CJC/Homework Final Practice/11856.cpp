#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main () {
    stack<int> s;

    string str;
    while(cin >> str) {
        if(str == "0")
            break;
        if(str != "+" && str != "-" && str != "*" && str != "/") {
            s.push(stoi(str));
        } else {
            int num2 = s.top(); s.pop();
            int num1 = s.top(); s.pop();

            if(str == "+") s.push(num1 + num2);
            else if(str == "-") s.push(num1 - num2);
            else if(str == "*") s.push(num1 * num2);
            else if(str == "/") s.push(num1 / num2);
        }
    }

    cout << s.top() << endl;
    
    return 0;
}