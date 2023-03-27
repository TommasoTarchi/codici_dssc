/* stesso programma di matrix.cpp in templates, ma usando smart pointers; unica differenza: deve essere specificata la dimensione (ovvero n se matrice nxn) della matrice come primo carattere del file */


#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <memory>


template <typename T>
class CMatrix {
    
public:
    
    std::unique_ptr<T[]> mat;
    int dim{0};
    
    void read_from_file(const std::string);
    void print_to_file(const std::string);
    
    /* devo definire il constructor anche se non mi serve, altrimenti non posso definire il copy constructor */
    CMatrix(void){};
    /* copy constructor */
    CMatrix(const CMatrix&);
    /* assignment operator overload */
    CMatrix& operator=(const CMatrix&);
};

template <typename T>
void CMatrix<T>::read_from_file(const std::string file_name) {
    
    std::ifstream f(file_name);
    f >> dim;
    
    mat = std::make_unique<T[]>(dim*dim);
    
    int i{0};
    while (!f.eof()) {
        f >> mat[i];
        i++;
    }
    f.close();
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

template <typename T> 
CMatrix<T>::CMatrix(const CMatrix<T>& a) {
    
    if (this != &a) {
        
        dim = a.dim;
        
        if (a.mat != nullptr) {
            mat = std::make_unique<T[]>(dim*dim);
            for (int i=0; i<dim*dim; i++) {
                mat[i] = a.mat[i];
            }
        }
    }
}

template <typename T>
CMatrix<T>& CMatrix<T>::operator=(const CMatrix<T>& a) {
    
    if (this != &a) {

        dim = a.dim;
        
        if (a.mat != nullptr) {
            if (mat == nullptr) {
                mat = std::make_unique<T[]>(dim*dim);
            } else {
                mat.reset(new T[dim*dim]);
            }
            for (int i=0; i<dim*dim; i++) {
                mat[i] = a.mat[i];
            }
        }
    }
    return *this;
}

template <typename T>
CMatrix<T> operator*(const CMatrix<T> A, const CMatrix<T> B) {
    
    CMatrix<T> R;
    R.dim = A.dim;
    R.mat = std::make_unique<T[]>(R.dim*R.dim);
    
    int k{0}, i{0};
    for (k=0; k<R.dim*R.dim; k++) {
        R.mat[k] = 0;
        for (i=0; i<R.dim; i++) {
            R.mat[k] += A.mat[(k/R.dim)*R.dim + i] * B.mat[i*R.dim + k%R.dim];
        }
    }
    
    return R;
}

template <typename T>
void print_to_screen(CMatrix<T> a) {
    
    int i{0}, j{0};
    for (i=0; i<a.dim; i++) {
        for (j=0; j<a.dim; j++) {
            std::cout << a.mat[i*(a.dim) + j] << " ";
        }
        std::cout << std::endl;
    }
}


/* ricordare che print_to_file stampa solo la matrice senza la dimensione all'inizio del documento */
int main() {
    
    CMatrix<int> A, B;
    
    A.read_from_file("A.txt");
    B.read_from_file("B.txt");
    
    auto C = A*B;
    C.print_to_file("C.txt");
    
    auto D = A;
    D.print_to_file("D.txt");
    
    auto E = A*B*D;
    E.print_to_file("E.txt");
    
    print_to_screen(A);
    
    return 0;
}
