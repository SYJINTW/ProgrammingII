#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <iterator>
#include <string>
#include <sstream>
using namespace std;
// A state contains five components:
// The first two components denote the current numbers of
// missionaries and cannibals at the left bank of the river.
// The third and fourth components denote the current numbers
// of missionaries and cannibals at the right bank.
// The fifth component denotes the location of the boat:
// 1 means "left bank" and -1 means "right bank".
using State = vector<int>;
class Crossing
{
private:
    vector<int> _npeople;  // how many missionaries and cannibals
                           // we use vector<int> as a tuple (int, int)
                           // the first integer indicate the number of missionaries
                           // the second integer indicates the number of cannibals
    set<list<State>> _paths;  // trial paths in progress
    set<State> _explored;     // explored states
    set<list<State>> _solutions;
public:
    // specify the numbers of missionaries and cannibals
    Crossing(vector<int> np): _npeople {np} { }
    // we may use s[4] to indicate the direction
    State Go(State s, int missionary, int cannibal)
    {
        s[0] = s[0] - s[4]*missionary;
        s[1] = s[1] - s[4]*cannibal;
        s[2] = s[2] + s[4]*missionary;
        s[3] = s[3] + s[4]*cannibal;
        s[4] = -s[4];
        return s;
    }
    // check the validity of a state
    bool valid(State s)
    {
        if (s[0]<0 || s[1]<0
            || s[2]<0 || s[3]<0) return false;
        // cannibals must not outnumber missionaries
        if (s[0]<s[1] && s[0]!=0) return false;
        if (s[2]<s[3] && s[2]!=0) return false;

        return true;
    }
    set<State> extend(State s)
    {
        set<State> nextStates;

        for (int m=0; m<=2; m++) {
            for (int c=0; c<=2; c++) {
                // a boat can take one or two people
                if (m+c>=1 && m+c<=2) {
                    State ss = Go(s, m, c);
                    if (valid(ss))
                        nextStates.insert(ss);
                }
            }
        }
        return nextStates;
    }
    // check if all people are at the right bank
    bool found(State s)
    {
        // s[4]==-1 means the boat is at the right bank
        if (s[0]==0 && s[1]==0 && s[4]==-1) return true;
        else return false;
    }
    void solve(int steps)
    {
        list<State> initialPath;

        State ss{_npeople}; // numbers of people at the left
        ss.push_back(0); // no missionary at the right bank
        ss.push_back(0); // no cannibals at the right bank
        ss.push_back(1); // 1 means the boat at the left bank

        initialPath.push_back(ss); // create the initial path
        _paths.insert(initialPath); // add the initial path into the path set _paths

        // same strategy as in the water jugs problem
        while (steps>0) {
            set<list<State>> newPaths;
            set<list<State>> oldPaths;

            for (auto p : _paths) {
                auto nextStates = extend(p.back());
                _explored.insert(p.back());
                for (auto s : nextStates) {
                    if (found(s)) {
                        auto np = p;
                        np.push_back(s);
                        _solutions.insert(np);
                    } else {
                        auto search = _explored.find(s);
                        if (search == _explored.cend()) {
                            auto np = p;
                            np.push_back(s);
                            newPaths.insert(np);
                        }
                    }
                }
                oldPaths.insert(p);
            }

            for (auto p : oldPaths) {
                _paths.erase(p);
            }
            for (auto p : newPaths) {
                _paths.insert(p);
            }

            --steps;
        }
    }
    void show_solutions()
    {
        for (auto path : _solutions) {
            for (auto s : path) {
                if (!s.empty()) {
                    cout << "(" << s[0] << ", " << s[1] << ")";
                    cout << "(" << s[2] << ", " << s[3] << ")";
                    if (s[4]==1) cout << " left\n";
                    else cout << " right\n";
                }
            }
            cout << "done" << endl;
        }
    }
};

int main()
{
    vector<int> people = {3, 3};
    Crossing p(people);
    p.solve(15);
    p.show_solutions();
}
