/* premise: when I instantiate a derived class the compiler does not
create a sort of "modified copy" of an instance of the base class;
what it does is to create an instance of the base class with attached
an "extention" that is the derived one; from this fact follows the
behaviour of overloaded and overridden functions */


/* basically (at least at this level) the difference between overloaded
and overridden member functions can be seen only when pointers are used
(see below for explanation and use of p in the code for example) */

/* pointers are "type-compatible" with the base class, in other words I
can declare a pointer to base class that actually points to a derived
class instance (dynamic polymorphism); in this case overloaded functions
are called from the "oldest class", while overridden ones from the
"youngest" (where the "oldest" class is the class declared in the pointer
and the "youngest" the one declared in the pointed object) */

/* to override a member function I must use the keyword 'virtual' in the
base class, and the function is then called 'virtual function'; if I also
add =0, then the function is said to be 'purely virtual'; a class that
contains at least one purely virtual member function is called 'abstract',
and it cannot be instantiated at all; when I define a derived class, if I
don't override all the purely virtual member functions of the base class,
then the derived class will be abstract too */

/* dynamic polymorphism is usually not used HPC because it is slow */


#include <iostream>


class Big {
public:

  void funz0() {
    std::cout << "funz0 called" << std::endl;
  }
  void funz1() {
    std::cout << "funz1 called from Big" << std::endl;
  };
  virtual void funz2() {
    std::cout << "funz2 called from Big" << std::endl;
  };
  virtual void funz3() = 0;   // if this is enabled then b cannot be instantiated
};

class Small: public Big {
public:

  void funz1() {    // overloaded
    std::cout << "funz1 called from Small" << std::endl;
  };
  // the keyword 'override' is not mandatory (but it helps the compiler and in debugging)
  void funz2() override {    // overridden
    std::cout << "funz2 called from Small" << std::endl;
  };
  void funz3() override {    // overridden if funz3() enabled in Big, otherwise defined here
    std::cout << "funz3 called from Small" << std::endl;
  };
};


int main() {

  //Big b;    // possible only if Big is not abstract
  Small s;
  //b.funz0();
  //b.funz1();
  //b.funz2();
  //b.funz3();   // purely virtual function (NEVER callable)
  s.funz0();
  s.funz1();
  s.funz2();
  s.funz3();

  std::cout << std::endl;

  Big* p=&s;
  p->funz0();
  p->funz1();   // since the function is overloaded (and not overridden) the compiler here calls funz0() from base class
  p->funz2();   // since the function is overridden the compiler here call it from derived class
  p->funz3();   // can be done only if funz3() is enabled in Big

  return 0;
}
