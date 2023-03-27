/* prove varie su passaggio di parametri a funzioni */


#include <iostream>

void funz(int&);   /* non presente in c (posso anche usare la notazione con asterisco come in c, ma questa è molto più comoda) */
void funzv(int*);
int unknown(int);

int main() {

    int a{1};
    funz(a);
    std::cout << a << std::endl;

    int v[] = {1, 2, 3};   /* i vettori si passano sempre per indirizzo */
    funzv(v);
    for (int i=0; i<3; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    funz(v[1]);
    std::cout << v[1] << std::endl;

    auto c = unknown(2);   /* auto assegna automaticamente alla variabile il tipo dell'output della funzione (si noti che l'effetto è 'instantaneo', cioè se dichiaro in una riga auto a e alla successiva a = unknown(2) non funziona); si usa se il tipo di ritorno della funzione è sconosciuto o troppo lungo da scrivere */
    std::cout << c << std::endl;

    return 0;
}

void funz(int& a) {

    a += 2;
}

void funzv(int* v) {

    for (int i=0; i<3; i++) {
        v[i]++;
    }
}

int unknown(int a) {

    return a + 3;
}
