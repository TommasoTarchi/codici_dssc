/* si parla di overloading anche se non è una dicitura esatta in questo caso, dato
che l'operatore che si definisce non esiste precedentemente (almeno non per la
classe da noi creata); si noti che ogni operatore ha una sua sintassi di overloading
(ad es. a << devo necessariamente passare uno stream su cui scrivere) */

/* si noti che l'operatore = è definito automaticamente per ogni classe che non
contenga puntatori; in quest'ultimo caso si deve fare l'overload di =, altrimenti
si ottengono memory leak a causa di doppi free (per dettagli vedi classes.cpp nella
cartella memory) */


#include <iostream>


class MyVector {

    double x;
    double y;
    double z;

public:

    MyVector(double a, double b, double c): x(a), y(b), z(c) {};

    // notice that we can overload the same operator with two different meanings (the signatur is what distinguishes the two "versions")
    friend MyVector operator+(const MyVector, const MyVector);
    friend MyVector operator+(const MyVector&, const int&);

    void operator[](const int index) {

    	if (index == 0) {
    	    std::cout << x << std::endl;
    	} else if (index == 1) {
            std::cout << y << std::endl;
    	} else if (index == 2) {
            std::cout << z << std::endl;
    	} else {
            std::cout << "wrong index" << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream&, const MyVector);
};

MyVector operator+(const MyVector a, const MyVector b) {

    MyVector c(0, 0, 0);

    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;

    return c;
};

MyVector operator+(const MyVector& v, const int& b){

    MyVector new_vec(0, 0, 0);

    new_vec.x = v.x+b;
    new_vec.y = v.y+b;
    new_vec.z = v.z+b;

    return new_vec;
};

/* di default (cioè prima dell'overloading) l'operatore << deve essere inteso
come una specie di freccia che mette ciò che sta a destra nello stream che
sta a sinistra (in questo senso std::cout può essere inteso come lo standard
output), in questo caso una sorta di generico stream di output; si noti che
per qualche motivo serve il simbolo & (se si toglie il compiler dà errore) */
std::ostream& operator<<(std::ostream& os, const MyVector v) {

    os << v.x << " " << v.y << " " << v.z << std::endl;
    return os;
}


int main() {

    MyVector v(1.4, 3, 5.3);
    MyVector w(0.6, 2.5, 1.7);

    v[1];
    v[3];

    auto z{v+w};
    std::cout << z;

    auto k = z+1;
    std::cout << k;

    return 0;
}
