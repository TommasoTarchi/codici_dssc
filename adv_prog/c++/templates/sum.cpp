/* sum() prende in input una lista di numeri, li converte ogni volta nel tipo indicato nell'istanza di sum() e restituisce la loro somma */


#include <iostream>


template <typename T>
T sum(const T a) {

    return a;
}
template <typename T, typename... Types>
T sum(const T a, const Types... numbers) {

    return a + sum(numbers...);
}


int main() {

    std::cout << sum<double>(44.5, 23, 5.3, 5.8) << std::endl;

    return 0;
}
