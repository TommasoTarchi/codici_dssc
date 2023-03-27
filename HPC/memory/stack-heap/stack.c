/* illustrazione di come funziona la memoria stack: ogni volta che la chiamata ad una
funzione finisce, la memoria da essa precedentemente occupata è liberata; SI NOTI che
non ostante la memoria cresca verso il basso, come indirizzo della funzione o variabile
viene preso quello del byte più in basso */


#include <stdio.h>


void funz1();
void funz2();
void funz3();
void funz4();
void funz4_int();


int main() {

  int a = 1;

  printf("indirizzo di a prima di chiamare le funzioni: %p\n", &a);
  
  funz1();
  funz2();
  funz3();

  funz4();
  funz1();

  printf("indirizzo di a dopo aver chiamato le funzioni: %p\n", &a);

  return 0;
}


void funz1() {
  
  int k;

  printf("indirizzo della variabile nella prima funzione: %p\n", &k);
}

void funz2() {

  char c;

  printf("indirizzo della variabile nella seconda funzione: %p\n", &c);
}

void funz3() {

  double d;

  printf("indirizzo della variabile nella terza funzione: %p\n", &d);
}

void funz4() {

  char k;
  printf("indirizzo della variabile nella quarta funzione: %p\n", &k);
  funz4_int();
}

void funz4_int() {

  char s;
  printf("indirizzo della variabile nella quarta funzione interna: %p\n", &s);
}
