#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int L = 0, R = 0, n;
	string s;
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == 'L') L++;
		else if(s[i] == 'R') R++;
	}
	cout << L+R+1 << endl;
}