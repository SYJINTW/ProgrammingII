#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <iterator>
using namespace std;
class Torch
{
private:
    struct State {
        vector<int> here;
        vector<int> there;
        int direction;
        State() { }
        State(vector<int> ini): here(ini.size()), there(ini.size()), direction {1} {
            for(int& i : here)
            {
                i = 1;
            }
        }
        State(const State& s): here{s.here}, there{s.there}, direction{s.direction} { }
        State& operator=(const State & s)
        {
            State localstate{s};
            swap(here, localstate.here);
            swap(there, localstate.there);
            direction = localstate.direction;
            return *this;
        }

        bool operator<(const State & s) const
        {
            return (here < s.here) || ((here == s.here) && (there < s.there))
            || ((here == s.here) && (there == s.there) && direction < s.direction);
        }

        void show()
        {
            for (auto t : here) {
                cout << t << " ";
            }
            cout << "| ";
            for (auto t : there) {
                cout << t << " ";
            }
            if (direction == 1)
                cout << " Left\n";
            else
                cout << " Right\n";
        }
    };

    using Choice = pair<int, State>;

    vector<int> walking_time;
    map<State, int> best_cost;
    map<State, State> prev_state;


    set<Choice> extend(Choice ch)
    {
        set<Choice> nextChoices;
        if (ch.second.direction == 1) {
            for (unsigned int i=0; i<ch.second.here.size(); ++i) {
                if (ch.second.here[i]==1) {
                    // alone
                    State ns(ch.second);
                    ns.here[i] = 0;
                    ns.there[i] = 1;
                    ns.direction = -1;
                    Choice nc = make_pair(ch.first-walking_time[i], ns);
                    nextChoices.insert(nc);
                    // with company
                    for (unsigned int j=i+1; j<ch.second.here.size(); ++j) {
                        if (ns.here[j]==1) {
                            State ns2(ns);
                            ns2.here[j] = 0;
                            ns2.there[j] = 1;
                            int total_cost =
                                (walking_time[i]>walking_time[j])
                                ? walking_time[i] : walking_time[j];
                            Choice nc2 = make_pair(ch.first-total_cost, ns2);
                            nextChoices.insert(nc2);
                        }
                    }
                }
            }
        } else {
            for (unsigned int i=0; i<ch.second.there.size(); ++i) {
                if (ch.second.there[i]==1) {
                    // alone
                    State ns(ch.second);
                    ns.here[i] = 1;
                    ns.there[i] = 0;
                    ns.direction = 1;
                    Choice nc(ch.first-walking_time[i], ns);
                    nextChoices.insert(nc);
                    // with company
                    for (unsigned int j=i+1; j<ch.second.there.size(); ++j) {
                        if (ns.there[j]==1) {
                            State ns2(ns);
                            ns2.here[j] = 1;
                            ns2.there[j] = 0;
                            int total_cost =
                                (walking_time[i]>walking_time[j])
                                ? walking_time[i] : walking_time[j];
                            Choice nc2(ch.first-total_cost, ns2);
                            nextChoices.insert(nc2);
                        }
                    }
                }
            }
        }

        return nextChoices;
    }

    bool found(State s)
    {
        if (s.direction==1) return false;
        for (auto e : s.here) {
            if (e!=0) return false;
        }
        return true;
    }

    void trace_back(State s)
    {
        State ini(walking_time);
        while (s<ini || ini<s) {
            s.show();
            State ns = prev_state[s];
            s = ns;
        }
        ini.show();
    }

public:

    Torch(vector<int> wt): walking_time {wt} { }
    void solve()
    {
        State initialState(walking_time);
        Choice item = make_pair(0, initialState);
        prev_state[initialState] = initialState;

        priority_queue<Choice> pq;
        pq.push(item);

        while (!pq.empty()) {
            Choice currentChoice = pq.top();
            pq.pop();

            if (found(currentChoice.second)) {
                cout << "Answer: ";
                cout << -currentChoice.first << "\n";
                cout << "Tracing back:\n";
                trace_back(currentChoice.second);
                break;
            }

            set<Choice> chs = extend(currentChoice);
            for (auto c : chs) {
                int newCost = c.first;
                State newState = c.second;
                auto search = best_cost.find(newState);
                if (search == best_cost.cend()) {
                    best_cost[newState] = newCost;
                    prev_state[newState] = currentChoice.second;
                    Choice newItem = make_pair(newCost, newState);
                    pq.push(newItem);
                } else if (newCost > best_cost[newState]) {
                    best_cost[newState] = newCost;
                    prev_state[newState] = currentChoice.second;
                    Choice newItem = make_pair(newCost, newState);
                    pq.push(newItem);
                }
            }


        }

    }
};

int main()
{
    vector<int> walking_time = {1, 2, 5, 10};
    Torch problem(walking_time);
    problem.solve();
}
