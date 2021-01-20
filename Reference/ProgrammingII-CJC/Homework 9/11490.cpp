#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

enum occupation {
    elder, 
    nursy,
    kitty,
    warrior,
    apprentice,
    medicent,
    deputy,
    leader
};

class Cat{
public:
    string name;
    occupation job;
    int age;

    Cat (string n, occupation j, int a) : name(n), job(j), age(a) {}
    bool operator<(const Cat &rhs) const {
        if(this->job < rhs.job) return true;
        else if(this->job > rhs.job) return false;
        // this->job == rhs.job
        if(this->job == apprentice) {
            if(this->age < rhs.age) return true;
            else if(this->age > rhs.age) return false;
        } else {
            if(this->age > rhs.age) return true;
            else if(this->age < rhs.age) return false;
        }
        // this->age == rhs.age
        if(this->name < rhs.name) return true;
        else return false;
    }

    // friend ostream& operator<<(ostream& os, const Cat& rhs) {
    //     os << rhs.name;
    //     return os;
    // }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, occupation> str_to_occup;
    str_to_occup.insert(pair<string, occupation>("elder", elder));
    str_to_occup.insert(pair<string, occupation>("nursy", nursy));
    str_to_occup.insert(pair<string, occupation>("kitty", kitty));
    str_to_occup.insert(pair<string, occupation>("warrior", warrior));
    str_to_occup.insert(pair<string, occupation>("apprentice", apprentice));
    str_to_occup.insert(pair<string, occupation>("medicent", medicent));
    str_to_occup.insert(pair<string, occupation>("deputy", deputy));
    str_to_occup.insert(pair<string, occupation>("leader", leader));

    
    vector<Cat> v;
    int N, M;
    while(cin >> N >> M) {
        int n = N;
        while(n--) {
            string name, strOccup;
            int age;
            cin >> name >> strOccup >> age;
            v.push_back(Cat(name, str_to_occup[strOccup], age));
        }

        sort(v.begin(), v.end());

        // auto end = (M >= N ? v.end() : v.begin() + M);
        // for (auto i(v.begin()); i != end; ++i)
        //     cout << *i << '\n';
        // v.clear();
        for (int i=0; i<min(M, N); ++i) {
            cout << v[i].name << "\n";
        }
        v.clear();
    }

    return 0;
}