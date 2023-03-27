/* this code illustrates the use of threadprivate
 * 
 * you can also see how atomic works and a proof of the presence of
 * an implicit barrier at the end of each parallel regions */


#include <stdio.h>
#include <omp.h>


int myid;   // global variable (threadprivate works only with global variables)


int main() {

    unsigned int sum=0;

    omp_set_num_threads(100);
    
    int myid;   // it doesn't work because it is not a global variable

   #pragma omp threadprivate (myid)

   #pragma omp parallel
    {
        myid=omp_get_thread_num();
       #pragma omp atomic
        sum++;
    }

   #pragma omp parallel
    {
        printf("I'm done (thread %d), and sum is %d\n", myid, sum);
    }

    return 0;
}
