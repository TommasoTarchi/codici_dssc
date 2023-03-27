/* here we show the use of destructor in the context of dynamic
polymorphism */


#include <iostream>


class Big {
  int* p{nullptr};

public:

  Big(int x) {
    p = new int;
    *p = x;
    std::cout << "constructor called from Big" << std::endl;
  }
  virtual void print() {
    std::cout << *p << std::endl;
  }
  virtual ~Big() {
    delete p;
    p = nullptr;
    std::cout << "destructor called from Big" << std::endl;
  }
};

class Small: public Big {
  double* g{nullptr};

public:

  Small(int x, double y): Big(x) {
    g = new double;
    *g = y;
    std::cout << "constructor called from Small" << std::endl;
  }
  void print() override {
    Big::print();   // call to Big's print
    std::cout << *g << std::endl;
  }
  ~Small() override {
    delete g;
    g = nullptr;
    std::cout << "destructor called from Small" << std::endl;
  }
};


int main() {

  // just to check that everything works properly in Big
  //Big b(5);
  //b.print();

  /* notice that an instantiation of the derived class implies an
   istantiation of the base one first; in fact both constructor and
   destructor are called when instantiating a derived class object;
   the reason why we override the destructor is that at the end of
   the program we need to call the destructor of the derived class
   before the one of the base class (but this is necessary only when
   using dynamic polymorphism) */
  //Small s0(4, 7.8);
  //s0.print();

  // let's now try with dynamic polymorphism
  //Small s(3, 8.1);   // if we don't allocate memory but use a pointer to an already existing object, the override of the destructor doesn't work
  Big* t = new Small(2, 3);
  t->print();
  delete t;
  t=nullptr;

  return 0;
}
