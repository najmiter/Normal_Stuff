#include <iostream>
#include <vector>
#include <functional>
#include <string>

template <typename... T>
class Delegate
{
private:
      using F = std::function<void(T...)>;

public:
      Delegate() = default;
      Delegate(F _f)
      {
            this->m_Functions.emplace_back(_f);
      }

      auto operator()(T... d) const noexcept -> void
      {
            for (auto &each : this->m_Functions)
            {
                  each(d...);
            }
      }

      auto operator+=(F _f) noexcept -> void
      {
            this->m_Functions.emplace_back(_f);
      }

private:
      std::vector<F> m_Functions;

}; // END OF <DELEGATE> CLASS

auto separate_thing(std::string str) -> void
{
      std::cout << "I, " << str << ", have nothing to with the Delegate class" << std::endl;
}

auto separate_int_thing(int i, std::string str) -> void
{
      std::cout << "I, " << str << ", and " << i << " have nothing to with the Delegate class" << std::endl;
}

auto main() -> int
{
      auto d = Delegate<std::string>([](std::string str)
                                     { std::cout << "PRINT: " << str << std::endl; });

      d += separate_thing; // added more functions
      d("good stuff");     // pura vector call ho jy ga es string k sath

      std::cout << "\n----------------------------------------\n"
                << std::endl;

      // construction time py add krna lazmi ni :D
      // we have the default constructor too
      auto d2 = Delegate<int, std::string>([](int i, std::string str)
                                           { std::cout << "PRINT: " << str << " and " << i << std::endl; });

      d2 += separate_int_thing;  // only the function pointer, not actually calling it
      d2(14, "string with int"); // sary functions en arguments k sath call ho jyn gy
}
