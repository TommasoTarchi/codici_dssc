#include <iostream>
#include <fstream>


template <typename T>
class Node {
    
private:
    T value;
    
public:
    Node<T>* next{nullptr};
    
    Node<T>(T& v): value(v) {};
    
    T getval() {
        return value;
    }
};

template <typename T>
class List {

private:
    Node<T>* first{nullptr};   // puntatore al primo nodo
    Node<T>* last{nullptr};   // puntatore all'ultimo nodo

public:
    
    /* da scrivere */
    List(){};
    
    /* funzione per aggiungere un nodo alla lista */
    void push_back(T& value) {
        
        if (last == nullptr) {   // caso di lista vuota
            last = new Node<T>(value);
            first = last;
        } else {
            last->next = new Node<T>(value);
            last = last->next;
        }
    }
    
    void print() {   // stampa la lista a partire dal primo nodo
        
        Node<T>* p = first;
        while (p != nullptr) {
            std::cout << p->getval() << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    
    ~List<T>() {   // distruttore (distrugge anche nodo)
        
        Node<T>* p = first;
        Node<T>* pn{nullptr};
        while (p != nullptr) {
            pn = p->next;
            delete p;
            p = pn;
        }
        p = nullptr;
        pn = nullptr;
    }
    
    List<T>(const List<T>&) {};   // copy-constructor
};


int main() {
    
    List<int> lista;
    
    /* legge i valori da salvare nella lista da file di testo (il primo valore letto è la lunghezza della lista) */
    int dim;
    std::ifstream f("linked_list.txt");
    f >> dim;
    int data[dim];
    for (int i=0; i<dim; i++) {
        f >> data[i];
    }
    for (int i=0; i<dim; i++) {
        lista.push_back(data[i]);
    }
    
    lista.print();
    
    /* creo copia della lista con copy-constructor */
    List<int> lista_copia(lista);
    
    lista_copia.print();
    
    return 0;
}
