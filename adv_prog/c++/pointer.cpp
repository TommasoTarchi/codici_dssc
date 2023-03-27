/* prove varie su puntatori e riferimenti (reference) */


#include <iostream>

int main() {

    int* p{nullptr};

    std::cout << p << std::endl;

    int a{2};   /* come in c */
    p = &a;
    std::cout << p << "  " << *p << std::endl;

    int& b{a};   /* b diventa alias di a (non presente in c) */
    b++;
    std::cout << a << std::endl;
    a++;
    std::cout << b << std::endl;

    return 0;
}
