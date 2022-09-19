#include <iostream>
int main(){
    std::string email = "realnajmiter@gmail.com";
    std::string Name, Company;

    int DaThing, DaOtherThing, i = 0;

    DaThing = email.find('@');
    DaOtherThing = email.find('.') - DaThing - 1;

    Name = email.substr(0, DaThing++);
    Company = email.substr(DaThing, DaOtherThing);

    Name = char(Name[0] > 96 ? Name[0] - 32 : Name[0]) + Name.substr(1, Name.length());
    Company = char(Company[0] > 96 ? Company[0] - 32 : Company[0]) + Company.substr(1, Company.length());

    std::cout<< "Hi " << Name << ", Welcome to " << Company << std::endl;
}
