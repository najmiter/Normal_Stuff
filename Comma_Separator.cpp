#include <iostream>

int main(){
    int n, d = 1, count = 0;

    std::cout<< "Enter a number: ";
    std::cin>> n;

    int num = n;

    while (n) {
        n /= 10;
        count ++;
        if (n) d *= 10;
    }

    n = num;
    std::cout<< "Comma separated number is = ";

    while (num) {
        if (count-- % 3 == 0 and n != num) std::cout << ", ";
        
        std::cout << (num / d);
        num %= d;
        d /= 10;
    }

    std::cout<< "\n";

}