/* shows the size of some arrays dynamically allocated using malloc:
 * notice the overhead (also because of padding) */

/* notice that malloc() never allocates less than 24B and that under
 * a certain size it always allocates in blocks of 8B*/
 
/* malloc_usable_size() (contained in malloc.h) is a function that
 * takes a pointer to a dynamic array (allocated by malloc()) and
 * returns the number of bytes (not bits) actually allocated (or
 * better: that is actually possible to allocate - remember that
 * malloc doesn't physically allocate memory of each element of the
 * array until it is actually accessed) */


#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "benchmark.h"
#ifdef __APPLE__
#include <malloc/malloc.h>
#define USABLE_SIZE(size) malloc_size((size))
#endif
#ifdef __linux__
#include <malloc.h>
#define USABLE_SIZE(size) malloc_usable_size((size))
#endif 
 
void demo( size_t N )
{

  int repeat        = 500;
  // uintN_t is a typedef for unsigned int of N bits (they are defined in stdint.h)
  uint64_t * values = (uint64_t *) malloc(N * sizeof(uint64_t));

  // prints the requested and the actually allocated memory
  size_t expected = USABLE_SIZE(values);
  printf("allocated %zu, reported allocation = %zu \n", N * sizeof(uint64_t), expected);
  BEST_TIME(USABLE_SIZE(values), expected, , repeat, 1, true);
  printf("\n");
      
  free(values);
  return;  
}


int main( void )
{
  
  printf("reported usable_size for 1B allocated: %zu \n", USABLE_SIZE(malloc(1)));
  //printf("reported usable_size for 1B allocated: %zu \n", malloc_usable_size((malloc(1))));  // same as above
  printf("reported usable_size for 4B allocated: %zu \n", USABLE_SIZE(malloc(4)));
  printf("reported usable_size for 8B allocated: %zu \n", USABLE_SIZE(malloc(8)));
  printf("reported usable_size for 16B allocated: %zu \n", USABLE_SIZE(malloc(16)));
  printf("reported usable_size for 32B allocated: %zu \n\n", USABLE_SIZE(malloc(32)));

  for( size_t N = 10; N < 100000000; N *= 10 )
    demo(N);

  return 0;
}
