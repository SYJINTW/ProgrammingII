#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

#define MAX_MOVE 80

const int goalRow[] = {-1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
const int goalCol[] = {-1, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2};

class State {
    public:
        int puzzle[4][4];
        int heuristic;
        int currentMove;
        int prevMove;
        int ex, ey; //position of empty tile

        State(int puzzle[4][4]) {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    this->puzzle[i][j] = puzzle[i][j];
            this->ex = -1;
            this->ey = -1;
            this->currentMove = 0;
            this->prevMove = -1;
            setHeuristic();
        }
        State(const State& s) {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    puzzle[i][j] = s.puzzle[i][j];
            currentMove = s.currentMove;
            prevMove = s.prevMove;
            ex = s.ex;
            ey = s.ey;
            heuristic = s.heuristic;
        }
        void setHeuristic() {
            int h = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (puzzle[i][j]) {
                        int goalX = goalRow[puzzle[i][j]];
                        int goalY = goalCol[puzzle[i][j]];
                        // Manhattan distance
                        h += abs(goalX - i) + abs(goalY - j);

                        // Linear conflict * 2
                        if (i == goalX) {
                            for (int k = j; k < 4; k++) {
                                if (puzzle[i][k] > 0 && goalRow[puzzle[i][k]] == i && puzzle[i][j] > puzzle[i][k])
                                h += 2;
                            }
                        }
                        if (j == goalY) {
                            for (int k = i; k < 4; k++) {
                                if (puzzle[k][j] > 0 && goalCol[puzzle[k][j]] == j && puzzle[i][j] > puzzle[k][j])
                                h += 2;
                            }
                        }
                    }
                }
            }
        this->heuristic = h;
        }
        void update(int i, int newx, int newy) {
            prevMove = i;
            swap(puzzle[newx][newy], puzzle[ex][ey]);
            ex = newx;
            ey = newy;
            currentMove++;
            setHeuristic();
        }
        /*overloaded operator
        (To sort elements in priority queue)*/
        bool operator<(const State& rhs) const {
            return currentMove + heuristic > rhs.currentMove + rhs.heuristic;
        }
};

int main() {
    int puzzle[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> puzzle[i][j];

    State s(puzzle);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!puzzle[i][j]) {
                s.ex = i;
                s.ey = j;
            }
        }
    }
    priority_queue<State> pq;
    pq.push(s);

    // direction of moving empty tile
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    while (!pq.empty()) {
        State curState = pq.top(); //top is the state with least f-value

        if (curState.heuristic == 0) { //means it same as goal state
            cout << curState.currentMove << endl;
            break;
        }
        pq.pop();

        if (curState.heuristic + curState.currentMove > MAX_MOVE)
            continue;
        for (int i = 0; i < 4; i++) {
            int newx = curState.ex + dx[i];
            int newy = curState.ey + dy[i];

            if (newx < 0 || newy < 0 || newx > 3 || newy > 3)
                continue;

            if (i == (curState.prevMove ^ 1))
                continue;

            State nextState = curState;
            nextState.update(i, newx, newy);
            pq.push(nextState);
        }
    }
    if (pq.empty())
      cout << -1 << endl;

  return 0;
}
