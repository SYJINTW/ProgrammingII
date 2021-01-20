#include <iostream>
#include <algorithm>
#include <array>

int main(){
    std::array<int, 10> s={5, 7, 4,
      2, 8, 6, 1, 9, 0, 3};

    // sort using the default operator<
    std::sort(s.begin(), s.end());
    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << '\n';
    return 0;
}
