#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <list>

#define ORIGIN 150
#define DIM 301
#define UP 0

using namespace std;

using State = array<int, 3>; // { x, y, direction }

int main() {
	bool occupied[DIM][DIM] = { false };
	// (dx, dy) is arranged so that adjacent (math) vectors differ in 45 degrees.
	int dx[8] = { 0, -1, -1, -1,  0,  1, 1, 1 };
	int dy[8] = { 1,  1,  0, -1, -1, -1, 0, 1 };
	// list<set<State>> today;
    set<State> today;
	int N;
	cin >> N;
	vector<int> growth;
	growth.reserve(30);
	int g;
	for (int i = 0; i < N; i++) {
		cin >> g;
		growth.push_back(g);
	}
	// today.push_back(set<State>{ State{ ORIGIN, ORIGIN, UP }});
    today = set<State> { State{ORIGIN, ORIGIN, UP} };
	int size = 0;
	for (int d = 0; d < N; d++) {
		// today.push_back(set<State>{});
		// for (auto branch : today.front()) {
        set<State> newStateSet;
		for (auto branch : today) {
			// Stretch this branch to color empty tiles.
			for (int i = 0; i < growth[d]; i++) {
				if (occupied[branch[0] + i * dx[branch[2]]][branch[1] + i * dy[branch[2]]]) continue;
				else {
					occupied[branch[0] + i * dx[branch[2]]][branch[1] + i * dy[branch[2]]] = true;
					size++;
				}
			}
			// Insert two new branches extending from the end of this branch.
			newStateSet.insert(State{ branch[0] + (growth[d] - 1) * dx[branch[2]] + dx[(branch[2] + 8 - 1) % 8], \
				branch[1] + (growth[d] - 1) * dy[branch[2]] + dy[(branch[2] + 8 - 1) % 8], (branch[2] + 8 - 1) % 8 });
			newStateSet.insert(State{ branch[0] + (growth[d] - 1) * dx[branch[2]] + dx[(branch[2] + 8 + 1) % 8], \
				branch[1] + (growth[d] - 1) * dy[branch[2]] + dy[(branch[2] + 8 + 1) % 8], (branch[2] + 8 + 1) % 8 });

		}
		// today.pop_front(); // Delete the previous set of branches, conserving memory. (Case 4 and 5 will cause MLE)
        today = newStateSet;
	}


	cout << size << '\n';

	return 0;
}