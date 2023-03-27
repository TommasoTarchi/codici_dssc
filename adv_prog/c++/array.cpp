/* gli std::vector sono puntatori che 'si autogestiscono' (non si devono
chiamare le alloc functions né liberare la memoria alla fine); possono
cambiare dimensione e essere riallocati come se fossero puntatori; se
non usati bene possono essere lenti (ad es. push.back() andrebbe usato
il meno possibile, e sostituito con resize()); sono quindi una forma di
array dinamici; la memoria allocata per un std::vector è contigua */

/* gli std::array sono molto simili agli static array in stile c; in
c++ è sempre consigliabile usarli al posto degli static array, perché la
performance è la stessa, ma permettono di non usare i puntatori,
conoscono la propria dimensione e possono essere usati con molti
algoritmi di c++ */

/* sia gli std::array che gli std::vector  sono template */

/* entrambi hanno un attributo .size() */

/* gli array non vengono inizializzati automaticamente, i vector sì */

/* per le matrici è sempre consigliabile allocare la memoria in modo
contiguo (come se fossero vettori), altrimenti le performance ne
risentono: cioè meglio non usare 'vettori di vettori' */


#include <iostream>
#include <vector>
#include <array>


template <typename T>
void modify(T v) {

    for (int i=0; i<v.size(); i++) {
        v[i] = i;
    }
}

template <typename T>
void modify2(T& v) {

    for (int i=0; i<v.size(); i++) {
        v[i] = i;
    }
}

template <typename T>
void print_roba(T v) {

    for (int i=0; i<v.size(); i++) {
        std::cout << v[i] << "  ";
    }
    std::cout << std::endl;
}


int main() {

    std::vector<int> vec;
    std::array<int, 5> arr;

    vec.resize(5);

    print_roba(vec);
    //print_roba(arr);   // comportamento imprevedibile, perché
                         // gli std::array non vengono inizializzati
                         // automaticamente (per vedere memory leak
                         // usare valgrind)

    /* si noti che se si passano std::vec o std::array come parametri
    a funzioni senza usare il simbolo &, essi vengono passati per
    valore (in altre parole il nome dell'oggetto passato non viene
    considerato come un array normale); se voglio passare per indirizzo
    in una funzione c-style posso usare &vec[0] oppure l'attributo
    vec.data() (totalmente equivalente) */
    modify(vec);
    print_roba(vec);

    modify2(vec);
    print_roba(vec);

    return 0;
}
