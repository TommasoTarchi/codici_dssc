/* here we present a way to implement a linked list such
 * that the research of a node with a given key is optimized:
 * notice that the pointer to the following node is stored
 * after the key, and (most important) that data are not
 * stored in the node, but in a separate array: this way,
 * the node is smaller, and the search is faster */

/* this is an example of hot and cold field separation */



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



#define _XOPEN_SOURCE 700  // ensures we're using c11 standard
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <time.h>


#define CPU_TIME (clock_gettime( id, &ts ), (double)ts.tv_sec +	\
		  (double)ts.tv_nsec * 1e-9)

#ifndef DATASIZE
#define DATASIZE 200
#endif


typedef struct node_t {
  double         key;
  struct node_t *next;
  void          *data;
} node;


#define N_default 10000

int main( int argc, char **argv )
{
  struct timespec ts;
  clockid_t       id = CLOCK_PROCESS_CPUTIME_ID;
  
  // -------------------------------------
  // startup
  
  int N    = N_default;
  
  if ( argc > 1 )
    N = atoi( *(argv+1) );


  // -------------------------------------
  // setup

  double *keys    = (double*)calloc( N, sizeof(double));
  char   *alldata = (char*)calloc( DATASIZE*N, sizeof(char));
  node   *last    = NULL;
  node   *first   = NULL;

  printf("creating and initializing %d nodes\n", N ); fflush(stdout);
  srand48( time(NULL) );

  for( int nn = 0; nn < N; nn++ )
    {
      node *new = (node*)calloc( 1, sizeof(node) );
      if ( last != NULL )
	last->next = new;
      else
	first = new;
      new ->key  = drand48();
      keys[nn] = new->key;
      new ->next = NULL;
      new ->data = alldata + DATASIZE*nn;
      memset( new->data, 0, sizeof(char)*DATASIZE);
      last = new;
    }


  printf("now let's search for all of them\n"); fflush(stdout);
  
  int NSHOTS    = N;
  double sum    = 0;
  
  double tstart = CPU_TIME;
  
  for( int ii = 0; ii < NSHOTS; ii++ )
    {      
      double key = keys[(int)(drand48() * N)];
      node *target = first;

      while ( target->key != key )
	target = target->next;
      sum += target->key;
    }

  double et = CPU_TIME - tstart;

  printf("timing for %d shots: %g\n", NSHOTS, et );

  node *target = first;
  while( target->next != NULL )
    {
      node *tmp = target->next;
      free(target);
      target = tmp;
    }
  
  return 0;
}
