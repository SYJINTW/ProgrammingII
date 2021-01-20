#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct State {
	int lv, hp, mhp;
	int dist;
	State(int lv, int hp, int mhp, int dist = 0): lv(lv), hp(hp), mhp(mhp), dist(dist) {}
};

bool vis[20][310][410];

int main() {
    //read the input
	int lv, hp, mhp, mdmg;
	int dmg[20], hl[20];
	cin >> lv >> hp >> mhp >> mdmg;
	for (int i = 1; i <= lv; i++)
		cin >> dmg[i] >> hl[i];

	queue<State> q;//the queue for BFS
	q.push(State(1, hp, mhp));//the initial state

	while (!q.empty()) {
		State s = q.front();
		if (!s.mhp)
			break;
		q.pop();

		//Calculate the next states
		// level up
		if (s.lv < lv && s.hp - mdmg > 0) {
			State t(s.lv + 1, s.hp - mdmg, s.mhp, s.dist + 1);
			if (!vis[t.lv][t.hp][t.mhp]) {
				vis[t.lv][t.hp][t.mhp] = true;
				q.push(t);
			}
		}

		// attack
		if (s.hp - mdmg > 0 || s.mhp - dmg[s.lv] <= 0) {
			State t(s.lv, s.hp - mdmg, max(0, s.mhp - dmg[s.lv]), s.dist + 1);
			if (!vis[t.lv][t.hp][t.mhp]) {
				vis[t.lv][t.hp][t.mhp] = true;
				q.push(t);
			}
		}

		// heal
		if (hp > mdmg && hl[s.lv] > mdmg) {
			State t(s.lv, min(hp, s.hp + hl[s.lv]) - mdmg, s.mhp, s.dist + 1);
			if (!vis[t.lv][t.hp][t.mhp]) {
				vis[t.lv][t.hp][t.mhp] = true;
				q.push(t);
			}
		}
	}//end while
	if (q.empty())
		cout << -1 << endl;
	else
		cout << q.front().dist << endl;
	return 0;
}
