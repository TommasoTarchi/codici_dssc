/* gli smart pointer sono puntatori che si autodelitano; in generale
meglio usare gli std::vector, se non è possibile gli smart pointer,
se neanche questo è possibile i raw pointer (cioè quelli normali) */


#include <iostream>
#include <memory>   // needed for smart pointers


int main() {

    int i{0};

    int N{5};

    std::unique_ptr<int[]> sp(new int[N]);
    /* stessa cosa spezzando il comando */
    //std::unique_ptr<int[]> sp;   // a questo punto è un sp == nullptr
    //sp = std::make_unique<int[]>(N)

    for (i=0; i<N; i++) {
        sp[i] = i;
    }

    for (i=0; i<N; i++) {
        //print
    }

    /* cambio dimensione al vettore allocato (non posso cambiare il tipo degli elementi) */
    int M{10};
    sp.reset(new int[M]);

    for (i=0; i<M; i++) {
        sp[i] = i+1;
    }

    for (i=0; i<M; i++) {
        //print
    }

    sp.reset(nullptr);   // just to show that it can be done

    return 0;
}
