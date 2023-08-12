#include <iostream>
#include <sstream>
#include <string>
// #include <algorithm> // std::reverse

int main(/* int _t_args, char** _string */) {
  std::string string{ "let's reverse each word in this string" };
  // std::string string{};

  // for (size_t i{1}; i < _t_args; i++) {
  //   string += _string[i];
  //   string += ' ';
  // }
  
  // string.pop_back();


  std::stringstream stream{ string };

  string.clear();

  while (stream.good()) {
    std::string each{};
    stream >> each; // lets -> stel

    // std::reverse(each.begin(), each.end());
    // string += each;

    // for (int i{ (int)each.length() - 1}; i >= 0; --i) {
    //   string += each[i];
    // }

    auto begin{ each.rbegin() };
    auto end{ each.rend() };
    for (; begin != end; begin++) {
      string += *begin;
    }

    string += ' ';
  }

  string.pop_back();

  std::cout << string << std::endl;

}
