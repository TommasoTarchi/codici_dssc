#include <iostream>


template <typename T1, typename T2>
class myclass {

public:
    T1 a;
    T2 b;

    myclass(T1& x, T2& y): a(x), b(y){};

    void print();
};

/* se definisco una funzione della classe all'esterno di quest'ultima
devo specificare di nuovo i typename */
template <typename T1, typename T2>
void myclass<T1, T2>::print() {

    std::cout << a << "  " << b << std::endl;
};


int main() {

    /* si noti che se qua non metto il const il compiler si lamenta */
    myclass<const int, const double> roba(10, 12.3);

    std::cout << roba.a << "  " << roba.b << std::endl;

    roba.print();

    return 0;
}
