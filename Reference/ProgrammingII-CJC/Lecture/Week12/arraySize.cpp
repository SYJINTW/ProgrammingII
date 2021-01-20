#include <iostream>

using namespace std;

template<class T,size_t N>
size_t get_array_size(const T (&arr)[N]){
	return N;
}

int main(){
   int a[4];

   // T is int and N is 2
   cout << get_array_size(a) <<endl;	//return 2
}
