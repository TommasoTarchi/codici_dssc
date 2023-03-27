/* in this program we access a variable byte by byte */



/* ────────────────────────────────────────────────────────────────────────── *
 │                                                                            │
 │ This file is part of the exercises for the Lectures on                     │
 │   "Foundations of High Performance Computing"                              │
 │ given at                                                                   │
 │   Master in HPC and                                                        │
 │   Master in Data Science and Scientific Computing                          │
 │ @ SISSA, ICTP and University of Trieste                                    │
 │                                                                            │
 │ contact: luca.tornatore@inaf.it                                            │
 │                                                                            │
 │     This is free software; you can redistribute it and/or modify           │
 │     it under the terms of the GNU General Public License as published by   │
 │     the Free Software Foundation; either version 3 of the License, or      │
 │     (at your option) any later version.                                    │
 │     This code is distributed in the hope that it will be useful,           │
 │     but WITHOUT ANY WARRANTY; without even the implied warranty of         │
 │     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          │
 │     GNU General Public License for more details.                           │
 │                                                                            │
 │     You should have received a copy of the GNU General Public License      │
 │     along with this program.  If not, see <http://www.gnu.org/licenses/>   │
 │                                                                            │
 * ────────────────────────────────────────────────────────────────────────── */



#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main( void )
{

  unsigned int i = 128;
  int size = sizeof(i);

  /*
   *  i is and integer variable, and as suche it requires 4 bytes
   *  let's explore how this 4 bytes are placed in memory
   */  
  
  for ( int j = 0; j < size; j++ )
   {
     printf("i is: %d\n", i );

      // now we access each byte of i
      char *byte = (char*)&i;
      for( int k = 0; k < size; k++ )
		printf("\t%p : %d\n", byte+k, *(byte+k) );      

      printf("\n");

      // now we multiply i by 256.
      // the operators << and >> read as "shift the argument's bit on the left [or right]
      // by the specified amount of bits "
      // In this case the amount of bits is 8, i.e. is is the same than multiplying by 256
      i <<= 8;

      // we are doing this because we want that only a single bit is set per each byte
      // among the i's bytes.
      // we started from a value of 1, i.e. only the first bit of the first byte of i was
      // set; multiplying  by 256 (i.e. bit-shifting by 8 positions) we move that bit
      // to the next byte.
    }

  return 0;
}
