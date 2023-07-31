#include <iostream>
#include <array>
#include <algorithm>
// #include <string>

void print(auto& array)
{
  // std::cout << array << std::endl;
  for (auto each : array)
    std::cout << each << ", ";

  std::cout << std::endl;
}

void reverse(auto& array)
{
  size_t i{}, j{ array.size() - 1 };
  while (i < j)
  {
    std::swap(array[i], array[j]);
    i++;
    j--;
  }

}

int main() 
{
  std::array<int32_t, 10> array
  {
    1,2,3,4,5,6,7,8,9,10
  };

  // std::string string{"something here"};

  print(array);

  reverse(array);

  print(array);



}
