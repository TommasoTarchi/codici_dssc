/* the variables of a struct are stored aligning them to a multiple of
their size, meaning that their address will always be at a distance from
the address of the struct that is a multiple of their size */

/* in the heap memory is allocated at multiples of 16 bytes (in 64-bit
architectures) */

/* in the stack variables are stored already in the most convenient
order (unless they are inside a struct) */


// see padding2.c for further details


#include <stdio.h>
#include <stdlib.h>


typedef struct {
  char c;
  int i;
  double d;
} mystruct;

typedef struct {
	char c;
	int i __attribute__((packed));
	double d __attribute__((packed));;
} mystruct_packed;


int main() {

  printf("size of char variables: %ld\n", sizeof(char));
  printf("size of int variables: %ld\n", sizeof(int));
  printf("size of double variables: %ld\n\n", sizeof(double));


  
  // struct
  mystruct s;
  printf("address of the struct in the stack: %p\n", &s);
  printf("address of the char variable in the struct: %p\n", &s.c);
  printf("address of the int variable in the struct: %p\n", &s.i);
  printf("address of the double variable in the struct: %p\n\n", &s.d);

  mystruct_packed sp;
  printf("address of the packed struct in the stack: %p\n", &sp);
  printf("address of the char variable in the packed struct: %p\n", &sp.c);
  printf("address of the int variable in the packed struct: %p\n", &sp.i);
  printf("address of the double variable in the packed struct: %p\n\n", &sp.d);



  // stack
  int x=1;
  char c='c';
  double d=3.45;

  printf("address of the int variable in the stack: %p\n", &x);
  printf("address of the char variable in the stack: %p\n", &c);
  printf("address of the double variable in the stack: %p\n", &d);

  int y=3;

  printf("address of the second int variable in the stack: %p\n\n", &y);



  // heap
  // notice that there is no difference between malloc and calloc
  char* b=(char*)malloc(sizeof(char));
  int* p=(int*)malloc(sizeof(int));

  printf("address of the char variable in the heap using malloc: %p\n", b);
  printf("address of the int variable in the heap using malloc: %p\n", p);


  char* bb=(char*)calloc(1, sizeof(char));
  int* pp=(int*)calloc(1, sizeof(int));

  printf("address of the char variable in the heap using calloc: %p\n", bb);
  printf("address of the int variable in the heap using calloc: %p\n", pp);

  free(b);
  free(p);
  free(bb);
  free(pp);


  return 0;
}
