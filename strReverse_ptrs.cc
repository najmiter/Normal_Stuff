#include <iostream>
#include <memory>

void strReverse(const std::string *ptr_str, size_t last)
{
    for (int i = last; i >= 0; i--)
    {
        std::cout<< ptr_str->at(i);
    }
    std::cout<< "\n";
}

void strReverse(std::unique_ptr<std::string> ptr_str)
{
    for (int i = ptr_str->size()-1; i >= 0; i--)
    {
        std::cout<< ptr_str->at(i);
    }
    std::cout<< "\n";
}

int main(){
    std::string main_str("with pointers");
    
    std::cout << "<---With pointer as an argument--->\n";
    strReverse(&main_str, main_str.size()-1); // better to just use {string_view} in this case
    
    std::cout << "<---With smart pointers--->\n";
    strReverse(std::make_unique<std::string>("hello world"));


}