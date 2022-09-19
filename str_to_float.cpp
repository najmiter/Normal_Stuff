// Make your own stof(...) for practice!
#include <iostream>
#include <cstring>
#include <cmath>

float strtoflo(const std::string& other){
    uint16_t
        idx     = other.find('.'),
        size    = other.length();

    float f_num = 0;
    // for (;number[idx] != '.'; idx++); // Hand made stuff :D (init idx to 0 for this to work)

    for (size_t i = 0; i < size; i++)
    {
        if (other[i] == '.') continue;
        f_num *= 10;
        f_num += int(other[i] - 48);
    }

    f_num /= pow(10, size - 1 - idx);
    return f_num;
}

int main(){
    std::string number ("3132.012321");

    std::cout<< strtoflo(number) << std::endl;
    
}
