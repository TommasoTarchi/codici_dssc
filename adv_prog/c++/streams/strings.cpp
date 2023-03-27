/* I can work with c-like strings using the <cstring> library
le std::string di c++ funzionano molto meglio */


#include <iostream>
#include <string>
#include <sstream>  // for streams of strings


// ' ' per characters, " " per strings


int main() {

    std::string str1{"hello"};
    std::string str2{"world"};
    std::string str3;
    std::string str4;
    int n{10};
    int m{0};

    str3 = str1;

    std::cout << str3 << std::endl;

    std::cout << str1+" "+str2 << "!" << std::endl;

    // stream of strings
    std::ostringstream oss;
    oss << str1 + ", " + str2 + " " << n << std::endl;
    str3 = oss.str();
    std::cout << str3;  // mette un endl alla fine

    // prende solo fino allo spazio e legge sequenzialmente le "parole"
    // riconosce automaticamente l'int
    std::istringstream iss(str3);
    iss >> str4;
    std::cout << str4 << std::endl;
    iss >> str4;
    std::cout << str4 << std::endl;
    iss >> str4;
    std::cout << str4 << std::endl;

    return 0;
}
