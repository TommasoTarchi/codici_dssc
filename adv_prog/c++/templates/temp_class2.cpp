/* similar to temp_class.cpp but with also a slightly more
complicated member function than print() (sum()) */


#include <iostream>


template <typename T, typename M>
class MyClass {
  T a;
  M b;

public:

  MyClass(const T& x, const M& y): a(x), b(y) {};

  void print();

  template <typename S, const int N>
  void sum(const S&);
};

template <typename T, typename M>
void MyClass<T, M>::print() {
  std::cout << a << " " << b << std::endl;
};

/* NOTICE that the typenames of the template class (T and M) MUST be
separated from the ones of the template function (S and N), as we
can see in the following two lines */
template <typename T, typename M>
template <typename S, const int N>
void MyClass<T, M>::sum(const S& z) {
  a += z+N;
  b += z+N;
};


int main() {

  MyClass<int, double> roba(3, 5.6);
  roba.print();
  roba.sum<double, 1>(2.4);
  roba.print();

  return 0;
}
