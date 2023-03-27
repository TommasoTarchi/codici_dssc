#include <iostream>


void print_stream(std::ostream& s) {
    s << "ciao" << std::endl;
}


int main() {

    /* posso usare print_stream per stampare su qualunque tipo di output
    stream (file, string, standard, ecc...) */
    print_stream(std::cout);
    print_stream(std::cerr);

    /* I can also define variables of type std::istream and std::ostream;
    however they must always be aliased (assignment is not enough) to
    an existing stream */
    std::ostream& os{std::cout};
    os << "riciao" << std::endl;

    return 0;
}
