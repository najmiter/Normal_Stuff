#include <iostream>

int main(){
    std::string email = "realnajmiter@gmail.com";
    std::string Name, Company;

    int DaThing, DaOtherThing;

    for (size_t i = 0; i < email.length(); i++){
        if (email[i] == '@') {
            DaThing = i;
            break;
        }
    }
    for (size_t i = DaThing; i < email.length(); i++){
        if (email[i] == '.') {
            DaOtherThing = i-DaThing-1;
            break;
        }
    }

    Name = email.substr(0, DaThing++);
    Company = email.substr(DaThing, DaOtherThing);

    Name = char(Name[0] > 96 ? Name[0] - 32 : Name[0]) + Name.substr(1, Name.length()) ;

    Company = char(Company[0] > 96 ? Company[0] - 32 : Company[0]) + Company.substr(1, Company.length()) ;

    std::cout<< "Hi " << Name << ", Welcome to " << Company << std::endl;

    



}