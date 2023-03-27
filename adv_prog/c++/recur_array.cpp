/* algoritmo ricorsivo per la stampa di un array */


#include <iostream>

void print_rec(int*, int);

int main() {

    int v[] = {1, 2, 3, 4, 5, 6};
    int size_v = sizeof(v) / sizeof(int);

    print_rec(v, size_v);

    return 0;
}

void print_rec(int* v, int size_v){

    if (size_v == 1) {
        std::cout << v[0] << std::endl;
        return;
    }

    size_v--;

    std::cout << v[0] << " ";
    print_rec(v + 1, size_v);
}
