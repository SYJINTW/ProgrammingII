#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	string str;
	char num_vowel;
	char last_vowel;

	// 第一層：母音出現次數
	// 第二層：最後一個母音相同
	map<int, map<char, vector<string>>> bucket; // map< int, map< char, vector<string> > >
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> str;
		num_vowel = 0;
		last_vowel = '\0';
		// 檢查每一個字串
		for(int k = 0; k < str.length(); k++)
		{	
			if(str[k] == 'a' || str[k] == 'e' || str[k] == 'i' || str[k] == 'o' || str[k] == 'u')
			{
				last_vowel = str[k];
				num_vowel++;
			} else;
		}
		// 存入 map 中
		bucket[num_vowel][last_vowel].push_back(str);
	}

	int comp = 0, uncomp = 0;
	for(auto smap : bucket)  // smap -> <int, map>
	{
		int tmp = 0;
		// Comp
		for(auto v : smap.second)  // v -> <char, vector>
		{
			comp += v.second.size()/2;
		}
		// Uncomp
		for(auto v : smap.second)  // v -> <char, vector>
		{
			tmp += v.second.size();
		}
		uncomp += tmp/2;
	}
	uncomp = uncomp - comp;

	int result;
	// 因為 comp 只能放在句尾，所以
	// comp <= uncomp 代表字尾不夠，所以數量就是comp數
	// comp > uncomp 代表字首不夠，所以要用 comp 充當字首，所以加起來除二
	if(comp > uncomp) result = (comp + uncomp)/2;
	else result = comp;

	cout << result << endl;

	return 0;
}