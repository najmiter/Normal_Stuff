#include <iostream>
#include "vector.hpp"

using Containers::Vector;

int main() {
  Vector array;
  array.push_back(8LL); // 1
  array.push_back(18LL);
  array.push_back(3LL);
  array.push_back(35LL);
  array.push_back(135LL);
  // std::cout << "Size = " << array.size() << std::endl;
  // std::cout << "Capacity = " << array.capacity() << std::endl;
  array.shrink_to_fit();

  // std::cout << "Size = " << array.size() << std::endl;
  // std::cout << "Capacity = " << array.capacity() << std::endl;

  for (auto each : array) {
    std::cout << each << std::endl;
  }

  // Vector other;
  // other.push_back(12LL);

  // other = array;

  
  // array.remove(67UL);
  
  // array.pop_front();
  // array.front() = 888LL;
  // std::cout << array.back() << '\n';




  // for (auto each : array) {
  //   std::cout << each << std::endl;
  // }

  // for (size_t i = 0; i < array.size(); i++) {
  //   std::cout << array.at(i) << std::endl;
  // }
  

  



}