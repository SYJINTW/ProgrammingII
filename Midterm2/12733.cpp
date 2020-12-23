#include <iostream>
#include <iomanip>
#include <string>
#define MOD 1000000007
using namespace std;

int main()
{
	long long int length, x;
	int t;
	string base;
	string str;
	cin >> t;
	while(t--)
	{
		cin >> x;
		cin >> base;
		length = base.length();

		for(long long int i = 0; i < x; i++)
		{
			int num = base[i];
			length = ((length-i-1)*(num-48))%MOD+(i+1)%MOD;
			if(base.length() <= x)
			{
				str = str.assign(base, i+1, base.length()-i);
				for(int k = 0; k < num-48-1 && base.length() <= x; k++)
				{
					base += str;
				}
			}
		}
		cout << length%MOD << endl;
	} 
}