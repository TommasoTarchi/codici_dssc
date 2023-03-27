/* first example of how to produce parallel regions and nested parallel
regions */

/* notice that messages are printed without an order; that is exactly
because parallel regions are parallel: to print them in a nice order we
should somehow serialize them (which is pointless) */

/* NOTICE (can be shown easly): children threads have the same id number 
 * of their parent thread */



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



#if !defined(_OPENMP)
#error you need to use OpenMP to compile this code, use the appropriated flag for your compiler
#endif

#if defined(__STDC__)
#  if (__STDC_VERSION__ >= 199901L)
#     define _XOPEN_SOURCE 700
#  endif
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <omp.h>


int main( int argc, char **argv )
{

  /* set number of threads to be spawn: first command needed to enable 
   * nested regions and second to set the number of threads (on the first 
   * level);
   * by default 4 threads are allowed on first level thread creation
   * (machine-dependent) and none (i.e. 1) on second and following levels */
  omp_set_nested(1);
  omp_set_num_threads(6);

 #pragma omp parallel
  {
    int nthreads = omp_get_num_threads();
   #pragma omp single
   //#pragma omp master   // same result but the following message won't be necessarely printed before all other messages
    printf("%d threads in the outer parallel region\n", nthreads);

	// set number of threads to be spawn in the inner region
	omp_set_num_threads(2);

   #pragma omp parallel
    {
      int nthreads_inner = omp_get_num_threads();
     #pragma omp single
      printf("\t%d threads in the inner parallel region\n", nthreads_inner);

     #pragma omp parallel num_threads(3)   // alternative way to set the number of threads
      {
        int nthreads_inner2 = omp_get_num_threads();
       #pragma omp single
        printf("\t\t%d threads in the inner inner parallel region\n", nthreads_inner2);
      }
	}
  }

  return 0;
}
