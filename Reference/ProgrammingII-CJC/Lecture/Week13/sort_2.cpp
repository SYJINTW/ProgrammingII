#include <iostream>
#include <algorithm>
#include <array>

int main() {
    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
    std::array<int,10>::iterator iter;
   /* sort using a standard library compare function object*/
   std::sort(s.begin(), s.end(),
             std::greater<int>());
   for(iter=s.begin(); iter != s.end(); ++iter){
       std::cout << *iter << " ";
    }
}
