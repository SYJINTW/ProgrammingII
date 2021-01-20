<<<<<<< HEAD
#include <iostream>

using namespace std;

class A {
private:
    static int count;
    int id;
public:
    A(){
        id = count ++;
        cout << "A's const:" << id <<  endl;
    }

    // copy constructor
    A(const A &x){
        id = count ++;
        cout << "A's copy const: " << id << endl;
    }

    // move constructor
    A(A&& a){
        id = count ++;
        cout << "A's move const: " << id << endl;
    }

    A& operator=(const A &x){
        cout << "A's = operator: from " << x.id << " to "<< id << endl;
        return *this;
    }

    ~A(){
        cout << "A's dest: " << id << endl;
    };
};

int A::count = 0;

A func(A a2){
    A a3 = a2;
    return a3;
}

int main(){
    A a1;
    A a4 = func(a1);
    return 0;
}
=======
#include <iostream>

using namespace std;

class A {
private:
    static int count;
    int id;
public:
    A(){
        id = count ++;
        cout << "A's const:" << id <<  endl;
    }

    // copy constructor
    A(const A &x){
        id = count ++;
        cout << "A's copy const: " << id << endl;
    }

    // move constructor
    A(A&& a){
        id = count ++;
        cout << "A's move const: " << id << endl;
    }

    A& operator=(const A &x){
        cout << "A's = operator: from " << x.id << " to "<< id << endl;
        return *this;
    }

    ~A(){
        cout << "A's dest: " << id << endl;
    };
};

int A::count = 0;

A func(A a2){
    A a3 = a2;
    return a3;
}

int main(){
    A a1;
    A a4 = func(a1);
    return 0;
}
>>>>>>> 2e49e55814ae1bff13eae079d830d0dac4dcd176
