// 用 b<(b+c-a)/2 來判斷
#include <iostream>

using namespace std;

int main()
{
	int n, a, b, c, day = 0, tmp;
	cin >> n;
	while(n--)
	{
		day = 0;
		cin >> a >> b >> c;
		if(a > b)
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		if(b > c)
		{
			tmp = b;
			b = c;
			c = tmp;
		}
		if(a > b)
		{
			tmp = a;
			a = b;
			b = tmp;
		}

		/*
		if(c-b>a){
			day += a;
			day += b;
		}
		else
		{
			day += c-b;
			a -= c-b;
			a /= 2;
			day += a*2;
			day += b-a;
		}
		cout << day << endl;
		*/
		
		if(b<(b+c-a)/2) cout << a+b << endl;
		else cout << a+(b+c-a)/2 << endl;
		
	}
}
