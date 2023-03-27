#include <iostream>
#include "templates.hpp"


int main() {

    int a{10};
    int b{2};
    std::cout << mysum(a, b) << std::endl << std::endl;

    myclass<const int, const double> classe(10, 12.3);
    std::cout << classe.a << "  " << classe.b << std::endl;
    classe.print();

    return 0;
}
