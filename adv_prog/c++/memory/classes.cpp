/* ogni volta che nella classe è presente un puntatore devo definire
anche la funzione speciale distruttore (altrimenti non verrebbe liberato
lo spazio puntato dall'oggetto, la funzione è chiamata automaticamente
alla fine del programma (o dello scope)), fare l'overload dell'operatore
= (per i motivi scritti sotto) e definire il copy constructor (per i
motivi scritti sotto, anch'esso viene chiamamto automaticamente alla fine
dello scope) */

/* quando faccio l'overload di un operatore dichiarandolo all'interno di
una classe, il primo argomento dell'operatore è di default del tipo
della classe stessa */


#include <iostream>


template <typename T>
class MyClass{
    T* data{nullptr};
    int size{0};

public:

    /* constructor */
    MyClass(const int N);
    /* destructor */
    ~MyClass();
    /* copy constructor */
    MyClass(const MyClass&);   // & needed
    /* assignment operator */
    MyClass& operator=(const MyClass&);   // & needed
    /* notare che non c'è bisogno di usare friend affinché = possa accedere
    alle variabili private della classe passata come argomento (probabilmente
    perché è in realtà un attributo della classe, e come tale può accedere
    alle variabili private di qualunque istanza della classe) */

    /* se so che non userò mai l'assignment operator e il copy constructor
    e non voglio perdere tempo a definirli, posso semplicemente metterli
    uguali a delete, almeno sono sicuro che chiunque provi ad usarli otterrà
    un errore in fase di compilazione, senza creare così memory leaks */
    // MyClass operator=(const MyClass) = delete;
    // MyClass(const MyClass) = delete;

    void print();
    void set_first(const T&);
};

template <typename T>
MyClass<T>::MyClass(const int N) {

    size = N;
    data = new T[N];
    for (int i=0; i<N; i++) {
        data[i] = i;
    }
    std::cout << "constructor called" << std::endl;   // just to check
}

template<typename T>
MyClass<T>::~MyClass() {

    delete[] data;
    data = nullptr;
    std::cout << "destructor called" << std::endl;   // just to check
}

/* dato che la classe contiene un puntatore, senza le modifiche seguenti
all'operatore = l'assignment copierebbe semplicemente l'indirizzo puntato
dall'oggetto a destra di = nel puntatore dell'oggetto a sinistra; in
questo modo si avrebbero due oggetti che puntano allo stesso spazio di
memoria, e si otterrebbe così un doppio free alla fine del programma
(ovvero alla chiamata dei distruttori) */
template <typename T>
MyClass<T>& MyClass<T>::operator=(const MyClass<T>& a) {

    //first check for self-assignment
    if (this != &a) {
        //copy non-dynamic variables
        size = a.size;
        //free memory of existing dynamic variables
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
        //create and copy dynamic variables
        if (a.data == nullptr) {
            data = nullptr;
        } else {
            data = new T[size];
            for (int i=0; i<size; i++) {
                data[i] = a.data[i];
            }
        }
    }
    return *this;
}

/* copy constructor: necessario per passare istanze della classe
come argomento a funzioni e operatori senza ottenere memory leaks */
template <typename T>
MyClass<T>::MyClass(const MyClass<T>& a) {

    //first check for self-assignment
    if (this != &a) {
        //copy non-dynamic variables
        size = a.size;
        //create and copy dynamic variables
        if (a.data == nullptr) {
            data = nullptr;
        } else {
            data = new T[size];
            for (int i=0; i<size; i++) {
                data[i] = a.data[i];
            }
        }
    }
}

template <typename T>
void MyClass<T>::print() {

    for (int i=0; i<size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MyClass<T>::set_first(const T& k) {

    data[0] = k;
}


int main() {

    MyClass<double> A(5), B(5);
    A.set_first(23);
    A.print();
    std::cout << std::endl;
    B.print();

    std::cout << std::endl;

    B = A;
    A.print();
    std::cout << std::endl;
    B.print();

    return 0;
}
