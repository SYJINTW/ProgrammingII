// <string>

// auto

// <vector>

/*==========================================================*/
// reference -> &
/*
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v;
	for(auto i = 0; i < 10; ++i) v.push_back(i*5);
	for(auto i : v) cout << setw(5) << i;
	cout << "\n";
	
	// didn't use reference, so y will not be changed
	for(auto y : v) y = y + 1;
	for(auto i : v) cout << setw(5) << i;
	cout << "\n";
	
	// use reference, will change y
	for(auto &y : v) y = y + 1;
	for(auto i : v) cout << setw(5) << i;
	cout << "\n";
}
*/

/*==========================================================*/
// lambda function -> []
// 真的是一個 function
// 所以如果不是用 reference 或是 pointer 的方式傳入參數，則不會更改原本的值
/*
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v;
	for(auto i = 0; i < 10; ++i) v.push_back(i*5);
	for(auto i : v) cout << setw(5) << i;
	cout << "\n";
	
	for_each(
		v.begin(), // 起點
		v.end(), // 終點
		//lambda function
		[] (int n){
			if(n%2==0) cout << n << " is even\n";
		}
		);
}
*/


/*==========================================================*/
// range based for loop -> for(auto i : vector)

/*==========================================================*/
// for_each() -> <algorithm>  for_each(起點, 終點, function)

/*==========================================================*/
//相同名稱的函數，會根據不同的類型的參數呼叫不同函式
/*
#include <iostream>
#include <functional>
#include <math.h>
#include <iomanip>
#define TOL 0.00001
using namespace std;
// 宣告 function 變數
void print(function<double(double)> f, double x)
{
    cout << "f(" << fixed << setprecision( 5 )  << x << ") = " << f(x) << endl;
}
void print(double x)
{
    cout << "ans = " << x << endl;
}
double fixed_point(function<double(double)> f, double guess)
{
    auto close_enough = [](double v1, double v2)
        { return fabs(v1-v2)<TOL; } ;
    auto next = f(guess);
    if (close_enough(next, guess)) return next;
    else return fixed_point(f, next);
}
double mysqrt(double x)
{
    return fixed_point([x](double y){return (y+(x / y))/2.0; }, 1.0);
}
double mycbrt(double x)
{
    return fixed_point([x](double y){return (y+(x / (y*y)))/2.0; }, 1.0);
}
int main() {
    auto x = 2.0;
    print(mysqrt, x);
    print(mycbrt(5.0));
}
*/

/*==========================================================*/
// class -> default is private, can put function inside class, need the constructor
// constructor: 為這個 class 設定初始值，是一個和 class 同名稱的 function，可以不只一個

#include <iostream>
#include <iomanip>
using namespace std;

class complex
{
	private:
		double _re;
		double _im;
	public:
		// constructor
		//特殊的用法
		complex(double r, double i) : _re{r}, _im{i} { }
		complex(double r) : _re{r}, _im{0.0} { }
		complex() : _re{0.0}, _im{0.0} { }

		// 窗口
		double re(){return _re;}
		double im(){return _im;}
};

int main(int argc, char const *argv[])
{
	double a, b;
	cin >> a >> b;
	complex x{a, b};
	complex y{a};
	complex z{};
	cout << "x: " << x.re() << "+" << x.im() << "i" << endl;
	cout << "y: " << y.re() << "+" << y.im() << "i" << endl;
	cout << "z: " << z.re() << "+" << z.im() << "i" << endl;
	return 0;
}











