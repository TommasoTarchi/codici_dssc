/* in generale il compilatore deve sapere at compile time la
segnatura "esatta" delle funzioni e delle classi che vengono
chiamate nel codice: in altre parole non può compilare usando
solo i template; pertanto usando gli headerper dichiarare le
funzioni e le classi e un source code per definirle (come si fa
solitamente), si dovrebbero mettere nell'header tutte le
segnature "esatte" che si chiameranno nel codice; ciò perché la
compilazione dei codici avviene in qualche modo indipendentemente
sui source code, pertanto quando il compiler va a compilare il
source code in cui sono definiti i template non conoscele
segnature "esatte" di funzioni e classi.

dover mettere tutte le segnature nell'header può indebolire molto
il ruolo dei template; il modo più semplice per risolvere questo
problema è definire direttamente i template nell'header, senza
usare un altro source code; in questo modo durante la compilazione
del source code principale il compiler può prendere le segnature
dal source code stesso e "ricostruirsi" le definizioni usando i
template nell'header */


#pragma once
#include <iostream>


template <typename T>
T mysum (const T& a, const T& b) {

    return a + b;
};


template <typename T1, typename T2>
class myclass {

public:
    T1 a;
    T2 b;

    myclass(T1& x, T2& y): a(x), b(y){};

    void print();
};

template <typename T1, typename T2>
void myclass<T1, T2>::print() {

    std::cout << a << "  " << b << std::endl;
};
