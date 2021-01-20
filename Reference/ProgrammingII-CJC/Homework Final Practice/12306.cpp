#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

bool explored[15][301][401] = { false };

class Problem {
    // [0] my level
    // [1] my HP
    // [2] monster HP
    // [3] step
    using State = vector<int>;
private:
    State initialState;
    int maxLevel;
    int MAtk;
    vector<vector<int>> eachLevel;
public:
    Problem(State input, int L, int MDMG, vector<vector<int>> Levels) : initialState(input), maxLevel(L), MAtk(MDMG), eachLevel(Levels) {}

    State operation(State s, int num) {
        if (num == 0) {
            // s[2] -= eachLevel[s[0]][0];
            s[0]++;
        } else if (num == 1) {
            // s[1] += eachLevel[s[0]][1];
            // s[1] = min (initialState[1], s[1]);
            s[2] -= eachLevel[s[0]][0];
        } else if (num == 2) {
            // s[0]++;
            s[1] += eachLevel[s[0]][1];
            s[1] = min (initialState[1], s[1]);
        }
        s[1] -= MAtk;
        s[3]++;
        return s;
    }

    set<State> extend(State s) {
        set<State> newStates;
        for (int i=0; i<3; ++i) {
            State tempS = operation(s, i);
            if(valid(tempS))
                newStates.insert(tempS);
        }
        return newStates;
    }

    bool found(State s) {
        return s[2] - eachLevel[s[0]][0] <= 0; //因為我每次更新state都會直接加入怪物扣血，如果怪物死了就已經贏了~
    }

    bool valid(State s) {
        if(s[1] > 0 && s[0] < maxLevel) {
            return true;
        } else {
            return false;
        }
    }

    int solve() {
        queue<State> q;
        // set<State> explored;

        q.push(initialState);
        // explored.insert(initialState);
        explored[initialState[0]][initialState[1]][initialState[2]] = true;

        while(!q.empty()) {
            State current = q.front();
            q.pop();
            
            auto newStates = extend(current);
            for (auto newState : newStates) {
                // cout << "answer: " << newState[0] << " " << newState[1] << " " << newState[2] << " " << newState[3] << endl;
                if(found(newState)) {
                    // cout << "answer: " << newState[0] << " " << newState[1] << " " << newState[2] << " " << newState[3] << endl;
                    return newState[3];
                } else {
                    if(explored[newState[0]][newState[1]][newState[2]] == false) {
                        explored[newState[0]][newState[1]][newState[2]] = true;
                        q.push(newState);
                    }
                }
            }
        }
        return -1;
    }
};


int main () {
    int L, HP, MHP, MDMG;
    cin >> L >> HP >> MHP >> MDMG;
    vector<int> input = {0, HP, MHP, 1};

    vector<vector<int>> eachLevel;

    for (int i=0; i<L; ++i) {
        vector<int> singleLevel;
        int DMG, HL;
        cin >> DMG >> HL;
        singleLevel.push_back(DMG);
        singleLevel.push_back(HL);
        eachLevel.push_back(singleLevel);
    }

    Problem p(input, L, MDMG, eachLevel);
    int num = p.solve();
    cout << num << endl;


    return 0;
}