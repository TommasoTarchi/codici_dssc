#include <iostream>


int main() {

    int N = 5;
    int i = 0;

    int* p{nullptr};
    int* pv{nullptr};

    p = new int;
    pv = new int[N];

    p[0] = 3;
    for (i=0; i<N; i++) {
        pv[i] = i;
    }

    std::cout << *p << std::endl;
    for (i=0; i<N; i++) {
        std::cout << pv[i] << " ";
    }
    std::cout << std::endl;

    delete p;
    delete[] pv;
    p = nullptr;
    pv = nullptr;

    return 0;
}
