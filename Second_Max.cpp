// by codeMite & Friends
// This code finds the second maximum number from any range of numbers
// WITHOUT USING ARRAYS!
// IKR! IT'S HOT! (i hope)

#include <iostream>
int main(){
    int numbers, max, secMax;
    for (size_t i = 0; i < 5; i++)
    {
        std::cout<< "Enter a number: ";
        std::cin>> numbers;

        if(!i) max = secMax = numbers;

        if (i == 1 and numbers < max) secMax = numbers;

        if (numbers > max) {
            secMax = max;
            max = numbers;
        }
        if (numbers > secMax and numbers < max) secMax = numbers;
    }

    std::cout<< "MAX = " << max << "\nSECOND MAX = " << secMax << std::endl;
}
