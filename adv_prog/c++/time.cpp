#include <iostream>
#include <chrono>
#include <thread>


class CSimple_Timer{
  
    std::chrono::time_point<std::chrono::steady_clock> t_start;
    std::string time_what;
    
    void print_time() {
        auto t_end = std::chrono::steady_clock::now();
        auto total = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
        std::cout<<time_what<<" took " <<total<< " milliseconds"<<std::endl;
    }
    
public:
    
    CSimple_Timer(std::string s):
        t_start{std::chrono::steady_clock::now()}, time_what{s} {}
    
    ~CSimple_Timer() {
        print_time();
    }
};


int main() {
    
    /* c style (non uso CSimple_Timer */
    std::chrono::time_point<std::chrono::steady_clock> t_start;
    t_start = std::chrono::steady_clock::now();  // we could just use auto
    
    // codice
    
    auto t_end = std::chrono::steady_clock::now();
    
    // di solito si usano i millisecondi
    auto total = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
    std::cout << "test time: " << total << std::endl;
    
    
    /* more c++ style: alla fine della zona compresa tra {} viene chimato automaticamente il distruttore, che stampa il tempo misurato */
    {
        CSimple_Timer t("test");
        
        // codice
    }
    
    return 0;
}
