#include <iostream>

using namespace std;


template <class T>
int compare(const T& v1,const T& v2){
    cout <<"data size:" << sizeof(v1) << endl;
    if(v1<v2)	return -1;
	return v2<v1;
}


int main(){
    int a = 2, b = 4;
    char c = 'a', d = 'Z';

    cout << compare(a, b) << endl;
    cout << compare(c, d) << endl;

    return 0;
}
