#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    getchar();
    int n = 1;

    map<char, char> m;
    m.insert(pair<char, char>('{', '}'));
    m.insert(pair<char, char>('[', ']'));
    m.insert(pair<char, char>('(', ')'));
    m.insert(pair<char, char>('<', '>'));

    while(N--) {
        bool ans = true;

        string str;
        getline(cin, str);

        stack<char> s;
        for(auto it = str.begin(); it != str.end(); ++it) {
            if( m.find(*it) != m.end() ) {
                s.push(*it);
            } else {
                if(s.empty()){
                    ans = false;
                    break;
                }
                char c = s.top();
                if(*it != m.find(c)->second) {
                    ans = false;
                    break;
                }
                s.pop();
            }
        }
        if(!s.empty())
            ans = false;
        std::cout << "Case " << n << ": " << ((ans)?"Yes\n":"No\n");
        n++;
    }
    return 0;
}