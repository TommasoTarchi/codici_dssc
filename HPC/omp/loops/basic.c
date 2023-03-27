/* here we see different ways of using for loops in combination with 
 * parallel regions */

/* reading results remember that children hreads have the same id number
 * as their parent thread */


#include <stdio.h>
#include <omp.h>


int main() {

    int N=10;

    omp_set_nested(1);
    omp_set_num_threads(5);

 
    /* each spawned thread executes the for loop independently */
    printf("first construct:\n");
   #pragma omp parallel
    {
        for (int i=0; i<N; i++) {
            printf("\tI'm %d\n", omp_get_thread_num());
        }
    }
 

    /* loop iterations are distributed among the previously
     * spawned threads */
    printf("second construct:\n");
   #pragma omp parallel
    {
       #pragma omp for 
        for (int i=0; i<N; i++) {
            printf("\tI'm %d\n", omp_get_thread_num());
        }
    }


    /* each thread spawnes a number of threads and for each 
     * parent thread the for loop is executed distributing 
     * iterations among the children threads */
    printf("third construct:\n");
   #pragma omp parallel
    {
       #pragma omp parallel for 
        for (int i=0; i<N; i++) {
            printf("\tI'm %d\n", omp_get_thread_num());
        }
    }


    /* just 'parallel for' without previously declaring a 
     * parallel region (same effect as the previous construct,
     * but here there is just one thread
     *
     * basically the same effect as the the second construct*/ 
    printf("first construct:\n");
   #pragma omp parallel for
    for (int i=0; i<N; i++) {
        printf("\tI'm %d\n", omp_get_thread_num());
    }


    return 0;
}
