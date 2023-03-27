#include <iostream>
#include <vector>
#include <algorithm>


int main() {

    int a{1};

    /* auto NON si riferisce al tipo di ritorno della funzione (è una
    cosa più complicata: mettere sempre auto); le variabili tra []
    vengono "catturate" automaticamente alla definizione della lambda
    function, quelle tra () vengono passate manualmente come in una
    funzione normale; il tipo di ritorno può anche essere omesso (sarà
    ritornato il più "logico") */
    /* si noti che le variabili definite nell'outer scope NON sono
    viste dalla lambda function a meno che non le si metta esplicitmente
    tra le captures */
    /* se in una lambda si aggiungono le parentesi tonde dopo le
    parentesi graffe la lambda viene definita ed eseguita subito */
    auto add1 = [a](int x, int y) -> double { return a+x+y; };

    std::cout << add1(1, 1) << std::endl;

    /* a è già stato catturato */
    a = 2;
    std::cout << add1(1, 1) << std::endl;


    a = 1;
    /* catturando per riferimento il valore nella funzione sarà cambiato
    ogni volta che lo cambio nello scope */
    auto add2 = [&a](int x, int y) -> double { return a+x+y; };
    std::cout << add2(1, 1) << std::endl;
    a = 2;
    std::cout << add2(1, 1) << std::endl;


    /* posso anche usarla una volta sola senza dichiararla */
    std::cout << [a](int x, int y) -> double { return a+x+y; }(1, 1) << std::endl;


    /* se voglio modificare i parametri catturati per valore devo per
    forza usare mutable (se li passo per reference non ce n'è bisogno) */
    a = 1;
    auto mod = [a](int b) mutable { a += 1; b += 1; return a+b; };
    std::cout << mod(1) << std::endl;


    /* possono tornare utili con gli std::vector */
    std::vector<int> vec, vec2;
    vec.resize(10, 0);
    vec2.resize(10, 0);

    int count{0};
    // unfortunately, you need an external variable for index
    std::generate(vec.begin(),vec.end(),[&count]{count++;return count*count;});

    // sort wants a function that accepts two parameters and compares them
    std::sort(vec.begin(),vec.end(),[](int x,int y){return x>y;});

    // for_each can be replaced by a range loop usually
    std::for_each(vec.begin(),vec.end(),[](int i){std::cout<<i<<std::endl;});

    std::transform(vec.begin(),vec.end(),vec2.begin(),[](int& x){return x+2;});


    return 0;
}
