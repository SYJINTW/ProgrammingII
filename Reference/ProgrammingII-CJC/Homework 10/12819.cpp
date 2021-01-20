// Not Accepted 9/10 time limit exceeded

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <list>
#include <array>

using namespace std;

struct Node {
    using State = array<int, 16>;
    State st;
    Node* parent;
    int level;
    int distance;
    int SIZE = 16;
    int LEN = 4;

    Node (State input, Node* p = nullptr) : st(input), distance(0), parent(p) {
        if(p) {
            level = p->level + 1;
        } else {
            level = 0;
        }
        cal_distance();
    }

    void cal_distance() {

        int i;
        int x=0, y=0, a, b;   // x, y is the current position
                              // a, b is the position in the goal
        bool in_col[16] = {};
        bool in_row[16] = {};

        for (i=0; i<SIZE; i++){
            if (st[i]!=0){    // the value in the current position
                a = (st[i]-1)%LEN;   // the position of the value in the goal
                b = (st[i]-1)/LEN;
                distance += (abs(x-a) + abs(y-b));  // Manhattan distance

                in_col[i] = (x == a);
                in_row[i] = (y == b);
            }
            if (++x >=LEN){   // move the the next position
                x = 0; ++y;
            }
        }

        // A* algorithm steps until now
        distance += level;

        // linear conflicts
        x = 0;
        y = 0;
        for (i=0; i<SIZE; ++i) {
            if(st[i] != 0) {
                if(in_col[i]) {
                    // only check one side(down)
                    for (int r = y; r <= LEN; ++r) {
                        int j = r*LEN + x;
                        if(st[j] == 0)
                            continue;
                        if(in_col[j] && st[j] < st[i])
                            distance += 2;
                    }
                }
                if(in_row[i]) {
                    // only check one side(right)
                    for (int c = x; c <= LEN; ++c) {
                        int j = y*LEN + c;
                        if(st[j] == 0)
                            continue;
                        if(in_row[j] && st[j] < st[i])
                            distance += 2;
                    }
                }
            }
            if (++x >= LEN){   // move the the next position
                x = 0; ++y;
            }
        }
    }
};

// struct cmp {
//     bool operator() (const Node* x, Node* y){
//         return x->distance > y->distance;
//     }
// };

bool cmp(const Node* x, Node* y){
    return x->distance > y->distance;
}

class SlideGame {
    using State = array<int, 16>;
private:
    State initialState;
    Node* sol = nullptr;
    int SIZE = 16;
    int LEN = 4;

public:
    SlideGame(State st) : initialState(st) {}

    State MoveBlock(State s, int from, int to) { // 
        State t = s;

        int temp = t[from];
        t[from] = t[to];
        t[to] = temp;

        return t;
    }

    set<State> extend(State s) {
        set<State> newStates;
        int pos, x, y;
        
        for (pos=0; pos<SIZE; ++pos) {
            if (s[pos] == 0) {
                x = pos % LEN;
                y = pos / LEN;
                break; // use pos as current position
            }
        }
        if (y < LEN-1) 
            newStates.insert( MoveBlock(s, pos, pos+LEN) );
        
        if (y > 0)
            newStates.insert( MoveBlock(s, pos, pos-LEN) );

        if (x < LEN-1)
            newStates.insert( MoveBlock(s, pos, pos+1) );

        if (x > 0)
            newStates.insert( MoveBlock(s, pos, pos-1) );

        return newStates;
    }

    bool found(State s) {
        for (int i=0; i<SIZE-1; ++i) {
            if(s[i] != i+1)
                return false;
        }
        return true;
    }

    int solve() {
        priority_queue<Node*, vector<Node*>, decltype(&cmp)> q(&cmp);
        set<State> explored;

        Node* current = new Node(initialState);
        if(found(current->st)) {
            return 0;
        }

        q.push(current);
        explored.insert(current->st);

        while(!q.empty()) {
            current = q.top();
            // explored.insert(current->st);
            q.pop();
            auto nextStates = extend(current->st);
            for (auto newState : nextStates) {
                if (found(newState)) {
                    sol = new Node(newState, current);
                    return sol->level;
                } else {
                    if (explored.find(newState) == explored.end()) {
                        Node* newNode = new Node(newState, current);
                        explored.insert(newState); //這個newState還沒被看過，所以我就丟進去queue並且標記成explored
                        q.push(newNode);
                    }
                }
            }
        }
        return -1;
    }
};

int main () {
    array<int, 16> map;

    for (int i=0; i<16; ++i) {
        cin >> map[i];
    }

    SlideGame game(map);
    int step = game.solve();
    cout << step << endl;

    return 0;
}