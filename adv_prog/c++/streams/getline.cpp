#include <iostream>
#include <string>
#include <sstream>


int main() {

    std::string s1{"prima"};
    std::string s2{"seconda"};
    std::string ss;

    std::ostringstream oss;

    oss << s1 << " ";
    oss << s2;
    std::cout << oss.str() << std::endl;

    /* in getline il primo argomento è l'input stream, il secondo
    la stringa su cui scrivere e il terzo il carattere in corrispondenza
    del quale si ferma la copiatura dello stream nella stringa */
    std::istringstream iss(oss.str());
    while (std::getline(iss, ss, ' ')) {
        std::cout << ss << std::endl;
    }

    return 0;
}
