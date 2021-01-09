// 有時間的話用 class 做一次
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <iterator>

using namespace std;

int main()
{
	int n;
	set <pair<int, string>> myset;
	string ui, name; 
	int age;
	cin >> n;
	while(n--)
	{
		cin >> ui;
		if(ui == "born")
		{
			cin >> name >> age;
			myset.insert({age, name});
		}
		else if(ui == "find")
		{
			cin >> name >> age;
			auto it = myset.find(pair<int, string>(age, name));
			if(it != myset.end()) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else if(ui == "kill")
		{
			cin >> name >> age;
			auto it = myset.find(pair<int, string>(age, name));
			if(it != myset.end()) myset.erase(it);
			else;
		}
		else if(ui == "young")
		{
			cout << myset.begin()->second << " " << myset.begin()->first << endl;
		}
	}
}





