/* the column (:) can be used in the construct that we see below; it is kind
of a contracted (and more efficient) if-else statement */


#include <stdio.h>


char * is_it_a(char c) {

  return (c=='a' ? "yes" : "no");

}


int main() {

  char c = 'a';
  printf("%s\n\n", is_it_a(c));

  char * s;
  s = 1!=2 ? "it is" : "it is not";
  printf("%s\n", s);

  return 0;
}
