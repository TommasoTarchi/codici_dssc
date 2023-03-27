/* la cosa migliore sarebbe non usare temp1 e temp2 ma una griglia temporanea e la funzione swap per gli std::vector (scambia i vector come se si usasse un puntatore di appoggio, evitando quindi l'allocazione dei temp ad ogni ciclo) */


#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>


class Mesh {
    
public:
    
    std::vector<double> grid;
    
    void init_corners() {
        
        grid.resize(11*11);
        
        int i{0};
        for (i=0; i<11; i++) {
            grid[i*11] = i*10;
        }
        for (i=1; i<11; i++) {
            grid[110+i] = (10-i) * 10;
        }
    }
    
    void init_inside(const double x) {
        
        int i{0}, j{0};
        for (i=1; i<10; i++) {
            for (j=1; j<10; j++) {
                grid[i*11+j] = x;
            }
        }
    }
    
    void print() {
        
        int i{0}, j{0};
        for (i=0; i<11; i++) {
            for (j=0; j<11; j++) {
                std::cout << grid[i*11+j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    void print_to_file(std::ofstream& f) {

        int i{0}, j{0};
        for (i=0; i<11; i++) {
            for (j=0; j<11; j++) {
                f << grid[i*11+j] << " ";
            }
            f << std::endl;
        }
    }
};

class Solver {
    
public:
    
    void Jacobi(Mesh& m) {
        
        int size{(int)std::sqrt(m.grid.size())};
        
        std::vector<double> temp1;
        temp1.resize(size);
        std::vector<double> temp2;
        temp2.resize(size);
        
        int i{0}, j{0};
        for (i=1; i<size-1; i++) {
            for (j=1; j<size-1; j++) {
                temp1[j] = temp2[j];
            }
            for (j=1; j<size-1; j++) {
                temp2[j] = 0.25 * (m.grid[i*size+j-1]+m.grid[i*size+j+1]+m.grid[(i-1)*size+j]+m.grid[(i+1)*size+j]);
            }
            
            if (i != 1) {
                for(j=1; j<size-1; j++) {
                    m.grid[(i-1)*size + j] = temp1[j];
                }
            }
        }
        
        for (i=1; i<size-1; i++) {
            m.grid[(size-2)*size + i] = temp2[i];
        }
    }
};


int main() {
    
    int iter{1000};
    
    Mesh g;
    g.init_corners();
    g.init_inside(0.5);
    
    Solver s;
    
    for (int i=0; i<iter+1; i++) {
        
        s.Jacobi(g);
        
        if (i%50 == 0) {
            std::ofstream f("Jacobi_data/" + std::to_string(i) + ".dat");
            g.print_to_file(f);
            f.close();
        }
    }
    
    return 0;
}
