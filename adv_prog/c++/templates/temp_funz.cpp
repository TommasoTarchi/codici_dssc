/* i template sono 'scheletri' di funzioni in cui non si dichiarano i tipi,
ogni volta che chiamiamo un template su un certo tipo di dato viene creata
un'istanza del template (ovvero una funzione) specifica per quel tipo.
l'uso della lettera T è una convenzione (a volte ad esempio si usa la M) */

/* quando uso delle librerie da me scritte devo includere già nei file in
cui definisco le funzioni le instanziazioni dei template, perché mentre
compila le funzioni il compiler ha bisogno di sapere quali saranno i tipi
delle variabili; le istanziazioni si fanno alla fine del file contenente
la definizione delle funzioni, e la sintassi è:
template tipooutput nomefunzione(tipoinput&, ...);
se intendo usare lo stesso template per più tipi di dati basta ripetere
l'istanziazione per tutti i tipi desiderati;
si noti però che tutto ciò può essere evitato (in realtà semplificando
molto anche l'uso delle librerie stesse) scrivendo la definizione del
template direttamente nell'header; vedi temp.cpp e temp.hpp la directory
'libraries' per esempio */


#include <iostream>


template <typename T>
void print (const T a) {

    std::cout << a << std::endl;
}

/* questo template ammette solo due argomenti dello stesso tipo */
template <typename T>
T mysum (const T a, const T b) {

    return a + b;
}

/* questo template ammette tipi diversi di input; si noti però che per
l'output deve necessariamente essere scelto un tipo */
template <typename T1, typename T2>
T1 doppiasum (const T1 a, const T2 b) {

    return a + b;
}

/* posso anche fare il template di numeri (solo interi); ad esempio qui
sotto ottengo lo stesso effetto che potrei ottenere in python usando un
decoratore */
template <typename T, short int N>
void sumN (T& n) {

    n += N;
}

/* variadic template: template di una funzione che può prendere in input
un numero variabile di argomenti (anche di tipo diverso); per prima cosa
si crea una funzione per il singolo argomento, dopodiché si definisce una
sorta di struttura ricrosiva per più argomenti */
template <typename T>
void print_lql(const T x) {
    std::cout << x << std::endl;
}
template <typename T, typename... Types>
void print_lql(const T a, const Types... roba) {

    /* si noti la struttura ricorsiva */
    std::cout << a << std::endl;
    print_lql(roba...);
}


int main() {

    int a{10};
    int b{2};
    double c{20};

    print(a);
    print(c);

    std::cout << mysum(a, b) << std::endl;
    std::cout << doppiasum(a, c) << std::endl;

    /* posso 'forzare' il tipo dell'output */
    print<int>(c);

    sumN<int, 3>(a);
    std::cout << a << std::endl;

    print_lql('z', 23, "ciao", 2.7);

    return 0;
}
