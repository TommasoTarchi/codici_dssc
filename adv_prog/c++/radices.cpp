#include <iostream>
#include <cmath>

int main() {
    
    /* semplice calcolo delle radici di un polinomio tramite delta */
    
    int a{0}, b{0}, c{0};
    
    std::cout << "inserire i coefficienti: " << std::endl;
    std::cin >> a >> b >> c;
    
    const int delta{b*b - 4*a*c};
    std::cout << delta << std::endl;
    
    if (delta >= 0) {
        
        std::cout << "le radici sono: " << (double)(-b + std::sqrt(delta))/2. << ", " << (double)(-b - std::sqrt(delta))/2. << std::endl;
        
    } else {
        
        std::cout << "le radici sono: " << -(double)b/2. << "+" << (double)std::sqrt(-delta)/2. << "i, " << -(double)b/2. << "-" << (double)std::sqrt(-delta)/2. << "i" << std::endl;

    }
    
    
    
    /* calcolo radici di un polinomio di terzo grado tramite bisezione sulla funzione 
     x^3-6x^2+11x-6=0 nell'intervallo [-10, 10] (ogni volta dimezzo l'intervallo e prendo
     la metà tale che ai due estremi la funzione abbia segno opposto) */
    
    double x1{-10};
    double x2{10};
    double D{x2 - x1};
    double funz{0};
    double result{0};
    
    while (D > 1e-9) {
        
        funz = (x1 + D/2)*(x1 + D/2)*(x1 + D/2) - 6*(x1 + D/2)*(x1 + D/2) + 11*(x1 + D/2) - 6;
        
        if (funz == 0) {
            
            result = x1 + D/2;
            break;
            
        } else if (funz < 0) {
            
            x1 = x1 + D/2;
            
        } else {
            
            x2 = x2 - D/2;
            
        }
            
        D = x2 - x1;
        result = x1 + D/2;
    }
    
    std::cout << "una radice dell'equazione è: " << result << std::endl;
    
    
    return 0;
}
