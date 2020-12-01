#include <iostream>
#include <iomanip>
#include <set>
#include <string>
using namespace std;

int main(){
	int n;
	string user_input;
	cin >> n;
	set <int> myset; //{1, 1, 1,12,100};
	//cout << *(--myset.end()) << endl;
	while(n--){
		cin >> user_input;
		// print
		// str1.compare(str2) 和 (str1 == str2) 效果類似
		// str1.compare(str2) 會回傳：'==' -> 0, '>' -> 1, '<' -> -1
		// (str1 == str2) 只有 true 和 false
		if(!user_input.compare("print")){
			if(myset.size() != 0){
				for(auto s : myset){
					cout << s;
					// myset.end() 會指向最後一個元素的 iterator
					// 但是我們要找的最後一個元素應該是在 --(myset.end)，也就是 myset.end() 的前一個
					if(s != *(--myset.end())) cout << " ";
					else cout << "\n";
				}
			} else;
		}
		// insert
		else if(!user_input.compare("insert")){
			int k;
			cin >> k;
			myset.insert(k);
		}
		// min
		else if(!user_input.compare("min")){
			if(myset.size() != 0){
				cout << *(myset.begin()) << endl;
			} else;
		}
		// range_eraser
		else if(!user_input.compare("range_erase")){
			int l, r;
			cin >> l >> r;
			for(int i = l; i <= r; i++){
				myset.erase(i);
			}
		}
	}

}