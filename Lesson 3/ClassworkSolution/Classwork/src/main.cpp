#include <iostream>
#include "../include/main.hpp"

int main()
{
    std::string name = "Johnny";
    std::string const surname = "Cash";

    auto lNameSurname = [=]()->std::string
        {
            return name + " " + surname;
        };

    std::cout << "Lambda full name: " << lNameSurname() << '\n';

    auto lAddToName = [&]()->void
        {
            name += surname;
        };

    lAddToName();
    std::cout << "Lambda add surname to name: " << name << '\n';

    FullNameFunctor f("Johnny", "Cash");
    std::cout << "Full Name Functor: " << f() << '\n';


    AddToNameFunctor f1(name, "Cash");
    f1();
    std::cout << "Functor AddToName: " << name << '\n';

    return 0;
}
