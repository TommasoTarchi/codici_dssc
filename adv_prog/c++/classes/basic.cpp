/* prime prove su creazione e manipolazione di classi */
/* le struct in c++ non sono come in c; in c++ sono classi a tutti gli effetti
(ad es. possono anche contenere funzioni), ma a differenza delle class hanno gli
attributi pubblici di default */


#include <iostream>

class Coord {

    double x;
    double y;

public:

    double z{2};

    Coord(double a, double b) {
        x = a;
        y = b;
    }  /* quando definisco una nuova classe viene posso definire anche una funzione
          "speciale" con lo stesso nome della classe (detta constructor) e senza alcun
          tipo di ritorno (neanche void) che permette di inizializzare le variabili della
          classe (anche quelle private) */

    void print() {
        std::cout << x << " " << y << " " << z << std::endl;
    }

    void setxy(int a, int b) {
        x = a;
        y = b;
    }

    friend void sumfriend(Coord, const int&);
};

class Coord2 {

    double x;
    double y;

public:

    double z{5};

    Coord2(double a, double b): x(a), y(b) {
    }  /* modo alternativo di usare il constructor; si rende
          necessario ad esempio nel caso in cui le variabili siano
          di un tipo per cui l'operatore '=' non è definito (ad es. classi),
          ma in generale è più comodo */

    void print() {

        std::cout << x << " " << y << " " << z << std::endl;
    }

    /* i seguenti comandi danno errore: all'interno della dichiarazione della
       classe le variabili (che siano pubbliche o private) non possono essere
       modificate direttamente */
    // x = 10;
    // y = 10;
    // z = 10;
};


void sumfriend(Coord c, const int& a) {

    c.x = 30;
    c.y += a;
    std::cout << c.x + c.y << std::endl;
}


int main() {

    Coord c(1, 2);
    c.print();

    /* non posso accedere alle variabili private direttamente */
    // c.x = 0;
    // c.y = 3;
    c.z = 4;
    c.print();

    /* oltre ad accedervi tramite funzioni attributo della classe, posso
    accedere alle variabili private anche tramite funzioni definite al
    di fuori della classe ma dichiarate anche all'interno di essa usando
    la parola chiave friend (si noti che come argomento deve essere passata
    la classe stessa); le funzioni friend non sono attributi della classe,
    ma normali funzioni definite all'esterno alle quali viene dato un
    'permesso speciale' per accedere alle variabili private di una classe */
    sumfriend(c, 1);

    c.setxy(10, 20);
    c.print();

    Coord2 c2(15, 25);  /* simile alla sintassi di python */
    c2.print();

    return 0;
}
