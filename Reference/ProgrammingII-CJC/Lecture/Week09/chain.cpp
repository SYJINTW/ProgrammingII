#include <iostream>

using namespace std;

class A {
private:
    int *a;

public:
    A(){
        cout << "A's const" << endl;
        a = new int[3];
    };

    ~A(){
        cout << "A's dest" << endl;
        delete [] a;
    };

    void printA(){
        cout << a[0] << a[1] << a[2] << endl;
    }
};


class B: public A {
public:
    B(){
        cout << "B's const" << endl;
    };

    ~B(){
        cout << "B's dest" << endl;
        printA();
    };
};

class C: public B {
public:
    C(){
        cout << "C's const" << endl;
    };

    ~C(){
        cout << "C's dest" << endl;
    };
};

int main(){

    C* test = new C;

    test->printA();

    delete test;
}
