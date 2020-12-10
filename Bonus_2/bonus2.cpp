#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
unsigned long long n, k, c, a;

int main(){
	while( cin >> n >> k )
	{
		c = 0;
		unsigned long long v[n];
		for(unsigned long long i = 0; i < n; i++){
			cin >> v[i];
		}

		for(unsigned long long i = 0; i < n; i++){
			for(unsigned long long j = 0; j < n; j++){
				if(i == j) continue;
				else{
					unsigned long long tmp = v[j], d = 1;
					while(tmp){
						tmp /= 10;
						d*=10;
					}
					tmp = v[i]*d + v[j];
					if(tmp % k == 0){
						c++;
					}
					else;
				}
			}
		}
		cout << c << endl;
	}
	return 0;
}