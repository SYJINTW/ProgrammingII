#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
// 10861 - Parentheses Matching
using namespace std;
map<char,char> parens = { { '{' , '}' },
                          { '(' , ')' },
                          { '<' , '>' },
                          { '[' , ']' } };
int main()
{
    string str;
    int ncases;
    cin >> ncases;
    //getline(cin, str);
    for (int i=1; i<=ncases; i++) {
        stack<char> S;
        getline(cin, str);
        bool valid = true;
        for (char c : str) {
            if (c=='{' || c=='[' || c=='(' || c=='<') {
                S.push(c);
            } else if (c=='}' || c==']' || c==')' || c=='>') {
                if (S.empty()) {
                    valid = false;
                    break;
                } else if (parens[S.top()] != c) {
                    valid = false;
                    break;
                } else {
                    S.pop();
                }
            }
        }
        if (!S.empty()) {
            valid = false;
        }
        cout << "Case " << i << ": ";
        if (valid) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

    }

}
