#include <iostream>
#include "11495.h"

using namespace std;


// the starting porint of your implementation
void Crossing::solve() {
    State initialState{_npeople};
    initialState.push_back(0);
    initialState.push_back(0);
    initialState.push_back(1);

    list<State> path;
    path.push_back(initialState);
    _paths.insert(path);

    while(!_paths.empty()) {
        set<list<State>> newPaths;
        for (auto p : _paths) {
            auto curState = p.back();
            _explored.insert(curState);
            auto extendState = extend(curState);
            for (auto newState : extendState) {
                if(found(newState)) {
                    auto np = p;
                    np.push_back(newState);
                    _solutions.insert(np);
                } else {
                    if(_explored.find(newState) == _explored.end()) {
                        auto np = p;
                        np.push_back(newState);
                        newPaths.insert(np);
                    }
                }
            }
        }
        _paths = newPaths;
    }
}

// extend to other possible states from a certain state
set<State> Crossing::extend(State s) {
    set<State> newStates;
    
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            if (i+j > 2)
                continue;
            if (i+j == 0)
                continue;
            State tempState = Go(s, i, j);
            if (valid(tempState)) {
                newStates.insert(tempState);
            }
        }
    }

    return newStates;
}

// may use s[4] to indicate the direction of move
State Crossing::Go(State s, int missionary, int cannibal) {
    s[0] -= s[4]*missionary;
    s[1] -= s[4]*cannibal;
    s[2] += s[4]*missionary;
    s[3] += s[4]*cannibal;
    s[4] *= -1;

    return s;
}

// check the validity of a state
bool Crossing::valid(State s) {
    if(s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0)
        return false;
    if((s[0] < s[1] && s[0] != 0 )|| (s[2] < s[3] && s[2] != 0))
        return false;
    return true;
}

// check if all people are at the right bank
bool Crossing::found(State s) {
    if (s[0] == 0 && s[1] == 0 && s[4] == -1) {
        return true;
    }
    return false;
}