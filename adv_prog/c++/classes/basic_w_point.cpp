/* you always need a constructor (unless you want all class
instances to carry the same data (for example you could leave
all the a's in MyValue instances equal to zero) */

/* if you don't have dynamic memory allocation in the class,
then the assignment operator works properly without
overloading */

/* if you have dynamic memory allocation in the class, then
you ALWAYS need a destructor (otherwise you get memory
leaks) */

/* if you have dynamic memory allocation inside the class,
to use the assignment operator you need to overload it, and
also if you think it could be used (for example to pass to a
function an instance of the class by value) you need to
define the copy constructor (not defined in this code); this
is because otherwise the copies of an instance of the class
would contain only a copy to the memory address of the
allocated variables (or vectors) in the first instance;
overloading the assignment operator and defining the copy
constructor you make sure that all the data are copied too */

/* to use std::move on instances of classes that contain
memory allocations, you need the move constructor */


#include <iostream>


class MyValue {
  int a{0};

public:
  MyValue(const int x): a(x) {};
  void print() {
    std::cout << a << std::endl;
  }
  void change_a(const int x) {
    a=x;
  }
};

class MyPoint {
  int* p{nullptr};

public:
  MyPoint(const int x) {
    p=new int;
    *p=x;
    std::cout << "constructor called" << std::endl;
  }
  void print() {
    std::cout << *p << std::endl;
  }
  void change_p_val(const int x) {
    *p=x;
  }
  /* si noti che (per qualche motivo) sono necessari i &,
     altrimenti ci sono memory leaks; inoltre si noti che la
     sintassi più corretta per l'overloading dell'assignment
     operator sarebbe più complicata: bisognrebbe prima di
     tutto fare un check per l'autoassignment (usando this)
     e SOPRATTUTTO prima di chiamare delete sul puntatore
     di *this (in questo caso p) si dovrebbe controllare
     che la memoria non sia già stata liberata, altrimenti
     si possono avere memory leaks */
  MyPoint& operator=(const MyPoint& m) {
    delete p;
    p=nullptr;
    p=new int;
    *p=m.p[0];
    return *this;
  }
  ~MyPoint() {
    delete p;
    p=nullptr;
    std::cout << "destructor called" << std::endl;
  }
};


int main() {

  //MyValue k(3);
  //MyValue h(2);
  //k.print();
  //h.print();
  //k=h;
  //k.print();

  MyPoint p(3);
  MyPoint b(2);
  p.print();
  b.print();
  p=b;
  p.print();

  return 0;
}
