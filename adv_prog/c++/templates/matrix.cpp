/* we assume to deal exclusively with square matrices */


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>


template <typename T>
class CMatrix {
    
public:
    
    std::vector<T> mat;
    int dim{0};
    
    void read_from_file(const std::string file_name);
    void print_to_file(const std::string);
};

template <typename T>
void CMatrix<T>::read_from_file(const std::string file_name) {
    
    std::ifstream f(file_name);
    T provv;
    
    while (!f.eof()) {
        f >> provv;
        mat.push_back(provv);
    }
    f.close();
    
    dim = (int)sqrt((double)mat.size());
}

template <typename T>
void CMatrix<T>::print_to_file(const std::string file_name) {
    
    std::ofstream f(file_name);
    
    int i{0}, j{0};
    for (i=0; i<dim; i++) {
        for (j=0; j<dim; j++) {
            f << mat[i*dim + j] << " ";
        }
        f << std::endl;
    }
    f.close();
}

/* overload di *: matrix product (righe per colonne) */
template <typename T>
CMatrix<T> operator*(const CMatrix<T> A, const CMatrix<T> B) {
    
    /* A, B ed R hanno le stesse dimensioni */
    CMatrix<T> R;
    R.dim = A.dim;
    R.mat.resize(R.dim * R.dim);
    
    /* calcolo della matrice prodotto (k indica l'elemento di R da calcolare) */
    int k{0}, i{0};
    for (k=0; k<R.dim*R.dim; k++) {
        R.mat[k] = 0;
        for (i=0; i<R.dim; i++) {
            R.mat[k] += A.mat[(k/R.dim)*R.dim + i] * B.mat[i*R.dim + k%R.dim];
        }
    }
    
    return R;
}


int main() {
    
    CMatrix<int> A, B;
    
    A.read_from_file("A.txt");
    B.read_from_file("B.txt");
    
    auto C = A*B;
    C.print_to_file("C.txt");
    
    return 0;
}
