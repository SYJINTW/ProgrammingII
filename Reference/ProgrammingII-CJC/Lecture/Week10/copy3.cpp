<<<<<<< HEAD
#include <cstring>
#include <algorithm>
#include <iostream>

// from https://stackoverflow.com/questions/3106110/what-is-move-semantics

class string{
    static int count;
    char* data;
    int id;

public:

    string(const char* p){
        size_t size = std::strlen(p) + 1;
        data = new char[size];
        std::memcpy(data, p, size);
        id = count++;
        std::cout << id << " constructor"<< std::endl;
    }

    ~string(){
        delete[] data;
        std::cout << id << " destructor"<< std::endl;
    }

    string(const string& that){
        size_t size = std::strlen(that.data) + 1;
        data = new char[size];
        std::memcpy(data, that.data, size);
        id = count++;
        std::cout << id << " copy constructor"<< std::endl;
    }

    string(string&& that){   // string&& is an rvalue reference to a string
        data = that.data;
        that.data = nullptr;
        id = count++;
        std::cout << id << " move constructor"<< std::endl;

    }

    string& operator=(string that){
        std::swap(data, that.data);
        std::cout << "assignment operator ("<< id<< "," << that.id<<")" << std::endl;
        return *this;
    }

    string operator+(const string& that){
        size_t size = std::strlen(that.data) + std::strlen(data) +1;
        char *tmp = new char[size];
        std::strcpy(tmp, data);
        std::strcat(tmp, that.data);
        delete [] data;
        data = tmp;
        std::cout << "+ operator ("<< id<< "," << that.id<<")" << std::endl;

        return *this;
    }
};

int string::count = 0;

string test(string x, string y){
    return x+y;
}

int main(){
    string x("Hello ");
    string y("World ");
    string a(x);                                    // Line 1
    string b(x + y);                                // Line 2
    string c(test(x, y));                           // Line 3

    return 0;
}
=======
#include <cstring>
#include <algorithm>
#include <iostream>

// from https://stackoverflow.com/questions/3106110/what-is-move-semantics

class string{
    static int count;
    char* data;
    int id;

public:

    string(const char* p){
        size_t size = std::strlen(p) + 1;
        data = new char[size];
        std::memcpy(data, p, size);
        id = count++;
        std::cout << id << " constructor"<< std::endl;
    }

    ~string(){
        delete[] data;
        std::cout << id << " destructor"<< std::endl;
    }

    string(const string& that){
        size_t size = std::strlen(that.data) + 1;
        data = new char[size];
        std::memcpy(data, that.data, size);
        id = count++;
        std::cout << id << " copy constructor"<< std::endl;
    }

    string(string&& that){   // string&& is an rvalue reference to a string
        data = that.data;
        that.data = nullptr;
        id = count++;
        std::cout << id << " move constructor"<< std::endl;

    }

    string& operator=(string that){
        std::swap(data, that.data);
        std::cout << "assignment operator ("<< id<< "," << that.id<<")" << std::endl;
        return *this;
    }

    string operator+(const string& that){
        size_t size = std::strlen(that.data) + std::strlen(data) +1;
        char *tmp = new char[size];
        std::strcpy(tmp, data);
        std::strcat(tmp, that.data);
        delete [] data;
        data = tmp;
        std::cout << "+ operator ("<< id<< "," << that.id<<")" << std::endl;

        return *this;
    }
};

int string::count = 0;

string test(string x, string y){
    return x+y;
}

int main(){
    string x("Hello ");
    string y("World ");
    string a(x);                                    // Line 1
    string b(x + y);                                // Line 2
    string c(test(x, y));                           // Line 3

    return 0;
}
>>>>>>> 2e49e55814ae1bff13eae079d830d0dac4dcd176
