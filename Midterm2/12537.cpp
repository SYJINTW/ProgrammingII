#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <tuple>
using namespace std;

int main()
{
	int n;
	string user_input;
	vector<int> v;
	set<pair<int, int>> s; // value, index

	cin >> n;
	while(n--)
	{
		cin >> user_input;
		if(user_input == "push_back")
		{
			int i;
			cin >> i;
			v.push_back(i);
			s.insert({i, v.size()});
		}
		else if(user_input == "pop_back")
		{
			if(v.empty()) continue;			
			int index = v.size();
			int value = *(v.rbegin());
			s.erase({value, index});
			v.pop_back();

		}
		else if(user_input == "find")
		{
			int i;
			cin >> i;
			if(v.size() < i) continue;
			cout << v[i-1] << endl;
		}
		else if(user_input == "max")
		{
			if(v.empty()) continue;
			cout << s.rbegin()->first << " " << s.rbegin()->second << endl;
		}
		else if(user_input == "min")
		{
			if(v.empty()) continue;
			cout << s.begin()->first << " " << s.begin()->second << endl;
		}
		else;
	}

}