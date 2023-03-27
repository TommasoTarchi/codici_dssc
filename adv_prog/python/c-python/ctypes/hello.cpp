#include <iostream>



extern "C" {

    void hello() {
        std::cout << "hello world!" << std::endl;
    }

}

extern "C" {

    const int sum(const int a, const int b) {
        return a + b;
    }

}
