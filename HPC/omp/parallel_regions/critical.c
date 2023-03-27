/* this code is to check that at the beginning of a crtical region
 * there is an implicit barrier */

/* also remember that all critical regions are considered to be part
 * of a unique big critical region, so that they cannot be executed
 * at the same time; to allow them to be executed at the same time we 
 * can rename the different regions, so that tey are distinguished */


#include <stdio.h>
#include <omp.h>


int main() {

   #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("waiting for all (tid: %d)\n", tid);

        #pragma omp barrier
        printf("done with barrier (tid: %d)\n", tid);

    }

   #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("waiting for all (tid: %d)\n", tid);

        #pragma omp critical
        printf("done with critical (tid: %d)\n", tid);

    }

    return 0;
}
