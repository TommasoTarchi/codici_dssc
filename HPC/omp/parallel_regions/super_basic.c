/* NOTICE that at the end of every parallel region there is an implicit barrier
 * to synchronize the threads */



#include <stdio.h>
#include <omp.h>       // needed for omp_get_num_threads() and omp_get_thread_num()
#include <stdlib.h>    // needed for getenv() and atoi()


int main() {

#if defined(_OPENMP)    // checks whether the program was compiled with openMP (i.e. with the option -fopenmp)
    
    int mode = atoi(getenv("OMP_NUM_THREADS"));   // gets the number of threads from the environment variable OMP_NUM_THREADS

    if (mode > 4) {

       #pragma omp parallel
        {
           #pragma omp master
            {
                int nthreas = omp_get_num_threads();
                printf("we are more than 4 threads, in particular %d:\n", nthreas);
            }
           #pragma omp barrier    // this is needed to avoid any thread to print the messge before the master

            printf("\thello world from thread %d\n", omp_get_thread_num());
        }

    } else {

       #pragma omp master   // in this case this is not necessary (since there is only the master)
        {
            printf("we could be more threads, but we are just the following:\n");
        }
        printf("\thello World from thread %d\n", omp_get_thread_num());
    }

#else

    printf("just another serial code doing nothing\n");

#endif

    return 0;
}
