#include <iostream>

template<typename T>
class Big1 {

private:
    T a1;
protected:
    T b1;
public:
    T c1;

    Big1(int x, int y, int z): a1(x), b1(y), c1(z) {};
};

class Big2 {

private:
    int a2;
protected:
    int b2;
public:
    int c2;

    Big2(int x, int y, int z): a2(x), b2(y), c2(z) {};
};

template<typename T>
class Small: public Big1<T>, private Big2 {

public:
    Small(T x, T y, T z, int k, int w, int r): Big1<T>(x, y, z), Big2(k, w, r) {}

    /* la funzione è sbagliata (non posso accedere alle variabili private delle classi genitrici) */
    // void print_private() {
    //    std::cout << a1 << " " << a2 << std::endl;
    // }

    void print_other() {
        std::cout << this->b1 << " " << b2 << " " << this->c1 << " " << c2 << std::endl;
    }

    /* se la base class (ovvero la classe genitrice) è templated, allora (per qualche motivo)
    per accedere alle variabili della class base dalla classe derivata il compiler ha bisogno
    che si specifichi this-> prima della variabile */
    void modify(const  T x, const T y, const int z, const int k) {
        this->b1 = x;
        this->c1 = y;
        b2 = z;
        c2 = k;
    }
};


int main() {

    Small<int> coso(1, 2, 3, 4, 5, 6);

    coso.print_other();

    // coso.b1 = 0;   // non posso accedere perché b1 è protected
    coso.c1 = 0;
    //coso.b2 = 0;   // non posso accedere perchè Small eredita da Big2 con private
    // coso.c2 = 0;  //  non posso accedere perchè Small eredita da Big2 con private

    coso.modify(30, 40, 50, 60);
    coso.print_other();

    return 0;
}
