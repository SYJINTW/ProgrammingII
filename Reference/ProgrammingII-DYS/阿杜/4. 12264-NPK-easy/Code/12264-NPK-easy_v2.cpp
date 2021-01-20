#include <iostream>
#include <queue>
#include <list>
#include <string>

using namespace std;

list<queue<int>> L;

void ENQUEUE(int id)
{
    auto it=L.begin();
    for (; it!=L.end(); ++it) {
        if(((*it).front())%3==id%3) break;
    }
    if(it!=L.end()) (*it).push(id);
    else
    {
        queue<int> tmp_q;
        tmp_q.push(id);
        L.push_back(tmp_q);
    }
}

void DEQUEUE()
{
    auto it=L.begin();

    int id=(*it).front();
    (*it).pop();
    cout << id <<endl;

    if(!(*it).size()) L.pop_front();
}

int main()
{
    string s;
    int id;

    int n_cmd;
    cin >> n_cmd;

    for(int i=0;i<n_cmd;++i)
    {
        cin >> s;
        if (s=="ENQUEUE") {
            cin >> id;
            ENQUEUE(id);
        } else if (s=="DEQUEUE") {
            DEQUEUE();
        } else {
        }
    }
}
