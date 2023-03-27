/* converte un numero in binario (ma stampa al contrario) */

#include <iostream>

int main() {
    
    int n{0};
    
    std::cout << "inserire numero: " << std::endl;
    std::cin >> n;
    std::cout << "codice binario corrispondente al numero inserito (da leggersi al contrario):  ";
    
    while (n > 1) {
        
        if (n % 2 == 1) {
            
            std::cout << "1";
            
        } else {
            
            std::cout << "0";
            
        }
        n /= 2;
        
    }
    
    if (n == 1) {
        
        std::cout << "1" << std::endl;
        
    } else {
        
        std::cout << "0" << std::endl;
    }

    return 0;
}
