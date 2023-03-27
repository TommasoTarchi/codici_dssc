/* example of optimized code */



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



#if defined(__STDC__)
#  if (__STDC_VERSION__ >= 199901L)
#     define _XOPEN_SOURCE 700
#  endif
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/times.h>
#include <time.h>
#include <math.h>




/* Conceptually, it is a loop over a number Np of particles
 * with tha aim of calculating the distance of each particle
 * from the center of the cells of a grid within a maximum distance
 * Rmax.
 *
 * The grid is actually not allocated.
 */


// look at the lecture about timing for motivations about the following macro
#define TCPU_TIME (clock_gettime( CLOCK_PROCESS_CPUTIME_ID, &ts ), (double)ts.tv_sec +	\
		   (double)ts.tv_nsec * 1e-9)

#define ITER 30

int main(int argc, char **argv)
{
  
  double           *parts;
  double           Rmax;
  int              Np, Ng;
  int              nIter;
  
  // timing-related variables
  struct timespec ts;

  Np = atoi( *(argv + 1) );
  Ng = atoi( *(argv + 2) );

  if ( argc > 3 )
    nIter = atoi( *(argv + 3) );
  else
    nIter = ITER;

  
  // allocate contiguous memory for particles coordinates
  parts = (double*)calloc(Np * 3, sizeof(double));

  Rmax = 0.2;
  
  // initialize random number generator
  //srand48(clock());   // change seed at each call
  srand48(997766);    // same seed to reproduce results

  // initialize mock coordinates
  printf("initialize coordinates..\n");
  for( int i = 0; i < 3*Np; i++)
    parts[i] = drand48();

 
  printf("LOOP :: "); fflush(stdout);
  
  double dummy = 0;
  double Rmax2 = Rmax * Rmax;
  double ctime = 0;
  double half_size = 0.5 / Ng;;
  double Ng_inv = (double)1.0 / Ng;  // we compute the inverse so that we can use the multiplication
									 // instead of the division in the loops (that because floating point
									 // division is much slower than multiplication)

  double *jks = (double*)calloc(Ng, sizeof(double));

  // we compute these once for all
  for( int i = 0; i < Ng; i++)
    jks[i] = (double)i * Ng_inv + half_size;
    
  int Np3 = Np * 3;


  // notice how we suggest the compiler to store in registers the most frequently used variables
  // notice also how we avoid to use pow() and sqrt() functions (very heavy)
  for ( int r = 0; r < nIter; r++ )
    {
		
      double tstart = TCPU_TIME;
      for( int p = 0; p < Np3; p += 3 )

		for( int i = 0; i < Ng; i++)
	  {
	    double register dx2 = parts[p] - jks[i]; dx2 = dx2*dx2;

		for( int j = 0; j < Ng; j++)
	      {
		double register dy = parts[p+1] - jks[j];
		double register dist2_xy = dx2 + dy*dy;

		for( int k = 0; k < Ng; k++)
		  {
		    double register dz = parts[p+2] - jks[k];
		    
		    double  dist2 = dist2_xy + dz*dz;
		    
		    if(dist2 < Rmax2)
		      dummy += sqrt(dist2);
		  }
	      }
	  }
	    
      ctime += TCPU_TIME - tstart;
    }
  
  printf("\t%g sec [%g]\n", ctime/nIter, dummy/nIter);

  free(jks);
  free(parts);
  
  return 0;
}
