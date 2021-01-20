#include <iostream>
#include "header/I2P2_test.h"
#include <ctime>

int main() {
  
#ifdef TEST_LIST
  std::cout << "Checking list ..." << std::endl;
  I2P2_test::check_list();
#endif

#ifdef TEST_VECTOR
  std::cout << "Checking vector ..." << std::endl;
  I2P2_test::check_vector();
#endif

  std::cout << "Finished" << std::endl;
  std::cout << (double)clock() / CLOCKS_PER_SEC << "S";
  return 0;
}

/* Here's how to test for both vector and list for type = double with g++:
 * g++ I2P2_main.cpp src/*.cpp -DTEST_VECTOR -DTEST_LIST -DDOUBLE -std=c++11 */

