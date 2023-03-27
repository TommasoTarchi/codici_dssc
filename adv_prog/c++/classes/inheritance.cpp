/* l'ereditarietà può essere: public, protected e private; gli effetti
sulle variabili nei tre casi sono i seguenti */

/* notare che l'accesso ai membri privati non è MAI consentito, neanche
alle classi figlie, o meglio: le classi figlie ereditano i membri privati
dei genitori (esattamente quei valori) ma non possono modificarli né
visualizzarli */

class CBase {
  public:
    int x;
  protected:   // singifica semplicemente private ma con accesso consentito alle child class
    int y;
  private:
    int z;
};

class CPublicDerived: public CBase {
  // x is public
  // y is protected
  // z is not accessible from CPublicDerived
};

class CProtectedDerived: protected CBase {
  // x is protected
  // y is protected
  // z is not accessible from CProtectedDerived
};

class CPrivateDerived: private CBase {
  // x is private
  // y is private
  // z is not accessible from CPrivateDerived
};



#include <iostream>


class Big {
private:
    int a{0};
protected:
    int b{0};
public:
    int c{0};
};

class Small: public Big {

public:
    void print() {
        std::cout << b << " " << c << std::endl;
    }
};


int main() {

    Small coso;

    // coso.a++;
    // coso.b++;
    coso.c++;

    std::cout << coso.c << std::endl;
    coso.print();

    return 0;
}
