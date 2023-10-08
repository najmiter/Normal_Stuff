#include <string_view>
#include <iostream>
#include <string>
#include <stack>

auto 
is_bracket(char _c)
-> bool
{
     static std::string_view brackets{ "(){}[]" };
     return brackets.contains(_c);
}

auto 
brackets_match(std::string_view _s)
-> bool
{
     std::stack<char> brackets;

     for (auto c: _s)
     {
          if (is_bracket(c))
          {
               if (c == '(' || c == '{' || c == '[')
               {
                    brackets.push(c);
               }
               else 
               {
                    if (brackets.empty()) return false;

                    auto top{ brackets.top() };
                    brackets.pop();

                    if ( c == ')' && top != '(' ||
                         c == '}' && top != '{' ||
                         c == ']' && top != '[')
                    {
                         return false;
                    }
               }
          }
     }

     return brackets.empty();
}

auto main() -> int
{
     std::string string{ "(())" };

     if (brackets_match(string.c_str()))
     {
          std::cout << "MATCHED" << std::endl;
     }
     else
     {
          std::cout << "NOT" << std::endl;
     }
}
