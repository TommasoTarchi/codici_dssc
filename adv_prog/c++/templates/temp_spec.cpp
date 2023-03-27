/* template specification */


#include <iostream>
#include <typeinfo>


template <typename T>
class CMyClass{
public:

    T field1;
    T field2;
    void function();
};


/* l'istruzione if constexpr (non presente negli standard precedenti al
c++17) è rivolta al compiler, vine quindi eseguita at compile time */
template <typename T>
void CMyClass<T>::function(){
    if constexpr(std::is_same_v<int,T>){
        std::cout<<"we are dealing with int"<<std::endl;
    }
    if constexpr(std::is_same_v<double,T>){
        std::cout<<"we are dealing with double"<<std::endl;
    }
    if constexpr(std::is_integral_v<T>){
        std::cout<<"something \"integer\" "<<std::endl;
    }else{
        std::cout<<"something non \"integer\" "<<std::endl;
    }
}


int main() {

    CMyClass<float> var;
    var.function();

    return 0;
}
