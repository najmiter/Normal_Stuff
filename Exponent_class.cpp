#include <iostream>
#include <cmath>
#include <utility>

class Exponent {
private:
    double y{};
    friend double operator*(double x, Exponent& y);
    friend std::ostream& operator<<(std::ostream& cout, const Exponent&);
public:
    explicit Exponent(double y) : y{y} {}
    Exponent& operator*() { return *this; }
    const Exponent& operator*() const { return *this; }

    double operator*(double y) const {
        return std::pow(this->y, y);
    }

};

double operator*(double x, Exponent& y) {
    return std::pow(x, y.y);
}


int main() {
//    double x{12.};
//    Exponent y{.5};
//    double result{x ** y}; // 4 ^ 3
//
//    std::cout << x << " ^ " << y << " = " << result << std::endl;

    double number{2.6};
    double* x{&number};
    const Exponent y{6};

    auto result{ y ** x }; // 10 ^ 2
//    auto result{ y ** (&(double&)(double&&)(2.5)) }; // 10 ^ 2
    std::cout << "result = " << result << std::endl;


}


std::ostream& operator<<(std::ostream& cout, const Exponent& exponent) {
    cout << exponent.y;
    return cout;
}
